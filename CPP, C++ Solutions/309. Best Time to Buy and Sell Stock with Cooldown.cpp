/*********************** Method-1 (Bottom up approach, TC-O(N), SC-O(N)) ********************
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1) return 0;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[n-1][0] = prices[n-1];
        dp[n-1][1] = 0;
        dp[n-2][0] = max(prices[n-2], prices[n-1]);
        dp[n-2][1] = max(0, prices[n-1] - prices[n-2]);
        
        for(int i = n-3; i >= 0; i--) {
            dp[i][0] = max(prices[i] + dp[i+2][1], dp[i+1][0]);
            dp[i][1] = max(dp[i+1][1], -prices[i] + dp[i+1][0]);
        }
        return dp[0][1];
    }
};
***********************************************************************************************/

/*********************** Method-2 (Bottom up approach, TC-O(N), SC-O(1)) ********************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1) return 0;
        vector<vector<int>> dp(3, vector<int>(2, 0));
        dp[(n-1)%3][0] = prices[n-1];
        dp[(n-1)%3][1] = 0;
        dp[(n-2)%3][0] = max(prices[n-2], prices[n-1]);
        dp[(n-2)%3][1] = max(0, prices[n-1] - prices[n-2]);
        
        for(int i = n-3; i >= 0; i--) {
            dp[i%3][0] = max(prices[i] + dp[(i+2)%3][1], dp[(i+1)%3][0]);
            dp[i%3][1] = max(dp[(i+1)%3][1], -prices[i] + dp[(i+1)%3][0]);
        }
        return dp[0][1];
    }
};