class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1);
        multiset<int> window;
        for(int i = 0; i < k-1; i++)
            window.insert(nums[i]);
        
        for(int i = k-1; i < n; i++) {
            window.insert(nums[i]);
            ans[i-k+1] = *window.rbegin();
            window.erase(window.find(nums[i-k+1]));
        }
        return ans;
    }
};