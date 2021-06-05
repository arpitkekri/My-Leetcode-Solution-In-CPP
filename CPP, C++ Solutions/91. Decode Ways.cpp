/***************Method-1 (Top-Down approach, TC-O(N), SC-O(N)) *******************************
class Solution {
public:
    int f(string s, int start, vector<int>& dp) {
        // Base cases
        if(start == s.size()) 
            return 1;
        
        if(s[start] == '0')
            return 0;
        
        // Check if it exist 
        if(dp[start] != -1) return dp[start];
        
        // Recursive call
        dp[start] = f(s, start+1, dp);
        if(start+2 <= s.size() && stoi(s.substr(start, 2)) <= 26) 
            dp[start] += f(s, start+2, dp);
        return dp[start];
    }
    
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(s, 0, dp);
    }
};
********************************************************************************************/

/************************Method-2 (Bottom up approach, TC-O(N), SC-O(N)) ********************

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        
        dp[n] = 1;
        dp[n-1] = s[n-1] == '0'? 0: 1;
        for(int i = n-2; i >= 0; i--) {
            // 2 Cases
            
            // Single digit 
            if(s[i] != '0')
                dp[i] += dp[i+1];
            
            // Double digit 
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
                dp[i] += dp[i+2];
        }
        return dp[0];
    }
};
*******************************************************************************************/

/************************Method-2 (Bottom up approach, TC-O(N), SC-O(1)) ********************/
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(2, 0);
        
        dp[n%2] = 1;
        dp[(n-1)%2] = s[n-1] == '0'? 0: 1;
        for(int i = n-2; i >= 0; i--) {
            int t = 0;
            // 2 Cases
            
            // Single digit 
            if(s[i] != '0') 
                t += dp[(i+1)%2];
            
            // Double digit 
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
                t += dp[(i+2)%2];
            
            dp[i%2] = t;
        }
        return dp[0];
    }
};