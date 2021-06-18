class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sell = prices[n-1];
        int profit = 0;
        for(int i = n-2; i >= 0; i--) {
            profit = max(profit, sell - prices[i]);
            sell = max(sell, prices[i]);
        }
        return profit;
    }
};