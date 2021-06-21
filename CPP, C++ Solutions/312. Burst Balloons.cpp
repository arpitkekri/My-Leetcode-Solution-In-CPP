// TC - O(N^3)
// SC - O(N^2)
// Criteria to split on last balloon I will burst

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                for(int k = i; k <= j; k++) {
                    int left = 0, right = 0, first = 1, last = 1;
                    
                    if(k-1 >= 0) 
                        left = dp[i][k-1];
                    
                    if(k+1 < n) 
                        right = dp[k+1][j];
                    
                    if(i-1 >= 0) 
                        first = nums[i-1];
                    
                    if(j+1 < n) 
                        last = nums[j+1];
                    
                    dp[i][j] = max(dp[i][j], left + right + nums[k]*first*last);
                }
            }
        }
        return dp[0][n-1];
    }
};