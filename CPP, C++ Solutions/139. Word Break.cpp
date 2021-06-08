// TC - O(N^2)
// SC - O(N)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[n] = true;
        
        string temp;
        for(int i = n-1; i >= 0; i--) {
            // Compute dp[i];
            temp = "";
            for(int j = i; j < n; j++) {
                temp += s[j];
                
                if(dict.find(temp) == dict.end()) 
                    continue;
                
                dp[i] = dp[i] || dp[j+1];
                if(dp[i] == true)
                    break;
            }
        }
        return dp[0];
    }
};