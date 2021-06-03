// TC : O(2*n) => O(N)
// SC : O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        // HR-II(nums, 0, n-1) = max(HR(nums, 0, n-2), HR(nums, 1, n-1));
        vector<int> dp(2, 0);
        vector<int> dp1(2, 0);
        
        dp[(n-2)%2] = nums[n-2];
        
        for(int i = n-3; i >= 0; i--)
            dp[i%2] = max(nums[i] + dp[i%2], dp[(i+1)%2]);
        
        dp1[(n-1)%2] = nums[n-1];
        
        for(int i = n-2; i >= 1; i--)
            dp1[i%2] = max(nums[i] + dp1[i%2], dp1[(i+1)%2]);
        
        return max(dp[0], dp1[1]);
    }
};