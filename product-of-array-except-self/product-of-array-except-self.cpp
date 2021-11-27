class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        
        // initialize
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1]*nums[i];
        }
        
        for(int i = n-2; i >= 0; i--) {
            suffix[i] = suffix[i+1]*nums[i];
        }
        
        vector<int> ans(n);
        ans[0] = suffix[1];
        ans[n-1] = prefix[n-2];
        
        for(int i = 1; i < n-1; i++) {
            ans[i] = prefix[i-1]*suffix[i+1];
        }
        
        return ans;
    }
};