class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        vector<int> oneTime(n, 0);
        int buy = prices[0];
        int ans = 0;
        for(int i = 1; i < n; i++) {
            int profit = prices[i] - buy;
            oneTime[i] = max(oneTime[i-1], profit);
            buy = min(buy, prices[i]);
            ans = max(ans, oneTime[i]);
        }
        int sell = prices[n-1];
        for(int i = n-2; i >= 0; i--) {
            int profit = sell - prices[i];
            profit = max(0, profit);
            if(i > 0)
                ans = max(ans, profit + oneTime[i-1]);
            sell = max(sell, prices[i]);
        }
        return ans;
    }
};