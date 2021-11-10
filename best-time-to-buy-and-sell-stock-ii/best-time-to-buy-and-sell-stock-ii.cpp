class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        int n = prices.size();
        dp[n-1][0] = 0;
        dp[n-1][1] = prices[n-1];
        for(int i = n-2; i >= 0; i--) {
            dp[i][0] = max(dp[i+1][0], dp[i+1][1] - prices[i]);
            dp[i][1] = max(dp[i+1][1], dp[i+1][0] + prices[i]);
        }
        return dp[0][0];
    }
};