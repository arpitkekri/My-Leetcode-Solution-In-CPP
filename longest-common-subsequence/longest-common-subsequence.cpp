class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(text1[i] == text2[j])
                    dp[i+1][j+1] = 1 + dp[i][j];
                else 
                    dp[i+1][j+1] = max({dp[i+1][j], dp[i][j+1]});
            }
        }
        return dp[m][n];
    }
};