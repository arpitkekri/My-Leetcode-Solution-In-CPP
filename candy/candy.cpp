class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 0;
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i-1])
                dp[i] = 1 + dp[i-1];
            else dp[i] = 1;
        }
        sum += dp[n-1];
        for(int i = n-2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1])
                dp[i] = max(dp[i], 1+dp[i+1]);
            sum += dp[i];
        }
        return sum;
    }
};