// TC - O(NlogN) 
// SC - O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i = 1; i < n; i++) {
            
            if(dp.back() < nums[i]) 
                dp.push_back(nums[i]);
            
            else {
                /***************************
                // This is also right but below code is more compact
                int lo = 0, hi = dp.size(), mid;
                hi = hi-1;
                while(lo < hi) {
                    mid = lo + (hi-lo)/2;
                    if(dp[mid] >= nums[i])
                        hi = mid;
                    else lo = mid + 1;
                }
                dp[lo] = nums[i];
                ******************************/
                int idx = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                dp[idx] = nums[i];
            }
        }
        return dp.size();
    }
};