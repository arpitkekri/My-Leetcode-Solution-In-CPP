// TC - O(n*k)
// SC - O(2*k) = O(k)
class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(2, vector<int>(5));
        for(int i = 0; i < 5; i++) dp[(n-1)%2][i] = 5-i;
        for(int i = n-2; i >= 0; i--) {
            dp[i%2][4] = 1;
            for(int j = 3; j >= 0; j--)
                dp[i%2][j] = dp[i%2][j+1] + dp[(i+1)%2][j];
        }
        return dp[0][0];
    }
};