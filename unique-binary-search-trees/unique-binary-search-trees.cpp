class Solution {
public:
    int numTrees(int n) {
        // catalan number
        // c0*c(n-1)  + c1*cn-2 + ... + cn-1*c0
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++)
            for(int j = 0; j < i; j++)
                dp[i] += dp[j] * dp[i-j-1];
        return dp[n];
    }
};