// TC - O(N^2) 
// SC - O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 1;
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++) {
            // Compute dp[i]
            for(int j = i-1; j >= 0; j--) {
                if(nums[i] > nums[j]) 
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

// Note: O(NlogN) solution exist watch it on YT good/famous Intrerview problem