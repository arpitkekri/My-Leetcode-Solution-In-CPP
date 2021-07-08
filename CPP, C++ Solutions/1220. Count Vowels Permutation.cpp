// TC - O(n)
// SC - O(1)
class Solution {
public:
    int countVowelPermutation(int n) {
        int M = 1e9 + 7;
        vector<vector<int>> dp(2, vector<int>(5, 1));
        for(int i = 1; i  < n; i++) {
            dp[i%2][0] = ((dp[(i-1)%2][1] + dp[(i-1)%2][2])%M + dp[(i-1)%2][4])%M;
            dp[i%2][1] = (dp[(i-1)%2][0] + dp[(i-1)%2][2])%M;
            dp[i%2][2] = (dp[(i-1)%2][1] + dp[(i-1)%2][3])%M;
            dp[i%2][3] = dp[(i-1)%2][2];
            dp[i%2][4] = (dp[(i-1)%2][2] + dp[(i-1)%2][3])%M;
        }
        for(int i  = 1; i < 5; i++)
            dp[(n-1)%2][0] = (dp[(n-1)%2][0] + dp[(n-1)%2][i])%M;
        
        return dp[(n-1)%2][0]%M;
    }
};