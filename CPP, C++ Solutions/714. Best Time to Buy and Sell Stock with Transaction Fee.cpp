/************************Method-1 (Bottom up approach, TC-O(N), SC-O(N)) ********************
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int>(2, 0));
        
        // Base case 
        // 0 -> sell
        // 1 -> buy
        // When I will Buy I will pay fee
        
        dp[n-1][0] = prices[n-1];
        dp[n-1][1] = 0;
        
        for(int i = n-2; i >= 0; i--) {
              // SELL              SELL NOW         NOT SELL NOW
            dp[i][0] = max(prices[i] + dp[i+1][1], dp[i+1][0]);
            
            // BUY              BUY NOW                         NOT BUY NOW
            dp[i][1] = max(-prices[i] - fee + dp[i+1][0], dp[i+1][1]);
        }
        return dp[0][1];
    }
};
***********************************************************************************************/

/************************Method-2 (Bottom up approach, TC-O(N), SC-O(1)) ********************
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        vector<vector<int>> dp(2, vector<int>(2, 0));
        
        // Base case 
        // 0 -> sell
        // 1 -> buy
        // When I will Buy I will pay fee
        
        dp[(n-1)%2][0] = prices[n-1];
        dp[(n-1)%2][1] = 0;
        
        for(int i = n-2; i >= 0; i--) {
            // SELL              SELL NOW                 NOT SELL NOW
            dp[i%2][0] = max(prices[i] + dp[(i+1)%2][1], dp[(i+1)%2][0]);
            
            // BUY              BUY NOW                         NOT BUY NOW
            dp[i%2][1] = max(-prices[i] -fee + dp[(i+1)%2][0], dp[(i+1)%2][1]);
        }
        return dp[0][1];
    }
};
********************************************************************************************/

/**************** Method-3 (Bottom up approach, TC-O(N), SC-O(1)) - MORE SPACE OPTIMIZATION **************/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size(), i;
        
        vector<int> dp(2);
        
        // Base case 
        // 0 -> sell
        // 1 -> buy
        // When I will Buy I will pay fee
        
        dp[0] = prices[n-1];
        dp[1] = 0;
        int temp;
        for(int i = n-2; i >= 0; i--) {
            // SELL       SELL NOW        NOT SELL NOW
            temp = max(prices[i] + dp[1], dp[0]);
            
            // BUY            BUY NOW            NOT BUY NOW
            dp[1] = max(-prices[i] -fee + dp[0], dp[1]);
            
            dp[0] = temp;
        }
        return dp[1];
    }
};