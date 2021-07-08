// TC - O(nm)
// SC - O(m)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> dp(m+1, 0);
        int ans = 0;
        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j < m; j++) {
                if(nums1[i] == nums2[j])
                    dp[j] = dp[j+1] + 1;
                else
                    dp[j] = 0;
                
                ans = max(ans, dp[j]);
            }
        }
        return ans;
    }
};