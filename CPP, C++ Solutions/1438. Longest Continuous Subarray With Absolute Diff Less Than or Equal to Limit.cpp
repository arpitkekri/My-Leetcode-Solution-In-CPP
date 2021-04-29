class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        if(n == 1) return 1;
        int i = 0, j = 1;
        int ans = 1, minVal, maxVal;
        multiset<int> s;
        s.insert(nums[0]);
        s.insert(nums[1]);
        while(i < n && j < n) {
            minVal = *s.begin();
            maxVal = *s.crbegin();
            if(maxVal - minVal <= limit) {
                ans = max(ans, j-i+1);
                j++;
                if(j != n) s.insert(nums[j]);
            }
            else {
                s.erase(s.find(nums[i]));
                i++;
            }
        }
        return ans;
    }
};