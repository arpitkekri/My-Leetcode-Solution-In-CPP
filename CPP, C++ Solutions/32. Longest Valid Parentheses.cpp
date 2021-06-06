/*********** Method-1 (Using stack, Kadane's type, TC-O(N), SC-O(N)) **************
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> stk;
        stk.push(-1);
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                stk.push(i);
            }
            else {
                stk.pop();
                if(stk.empty())
                    stk.push(i);
                else 
                    res = max(res, i-stk.top());
            }
        }
        return res;
    }
};
*******************************************************************************************/

/************** Method-2 (Bottom-Up, TC-O(N), SC-O(N)) **********************************/
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), i, j, res = 0;
        vector<int> dp(n, 0);
        
        // dp[0] = 0;
        for(i = 1; i < n; i++) {
            if(s[i] == '(')
                dp[i] = 0;
            else {
                j = i - dp[i-1] - 1;
                
                if(j >= 0 && s[j] == '(') {
                    dp[i] = dp[i-1] + 2;
                    if(j-1 >= 0)
                        dp[i] += dp[j-1];
                }
            }
            
            res = max(res, dp[i]);
        }
        
        return res;
    }
};