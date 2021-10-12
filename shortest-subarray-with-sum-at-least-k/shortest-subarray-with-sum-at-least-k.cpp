class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n+1, 0);
        
        for(int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }
        
        int ans = n+1;
        deque<int> dq;
        for(int j = 0; j <= n; j++)  {
            
            while(!dq.empty() && prefix[j] <= prefix[dq.back()])
                dq.pop_back();
            
            while(!dq.empty() && prefix[j] >= prefix[dq.front()] + k) {
                ans = min(ans, j-dq.front());
                dq.pop_front();
            }
            
            
            
            dq.push_back(j);
        }
        
        return ans == n+1? -1: ans;
        
    }
};