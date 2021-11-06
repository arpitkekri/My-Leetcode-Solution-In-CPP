class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1);
        deque<int> dq;
        for(int i = 0; i < k; i++) {
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        ans[0] = nums[dq.front()];
        for(int i = k; i < n; i++) {
            while(!dq.empty() && dq.front() <= i-k)
                dq.pop_front();
            
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            
            dq.push_back(i);
            ans[i-k+1] = nums[dq.front()];
        }
        return ans;
    }
};