class Solution {
public:
    int helper(vector<int> &prices, int start, bool isBuy, vector<vector<int>> &dp) {
        if(start >= prices.size())
            return 0;
        
        // if already cumputed
        if(dp[start][isBuy] != -1) 
            return dp[start][isBuy];
        
        int ans = 0;
        
        // Buy it if you haven't
        if(!isBuy)
            ans = max(ans, helper(prices, start+1, true, dp) - prices[start]);
        
        // Sell it if buy already
        if(isBuy)
            ans = max(ans, prices[start] + helper(prices, start+2, false, dp));
        
        // Do nothing on this day
        ans = max(ans, helper(prices, start+1, isBuy, dp));
        
        return dp[start][isBuy] = ans;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return helper(prices, 0, false, dp);
    }
};