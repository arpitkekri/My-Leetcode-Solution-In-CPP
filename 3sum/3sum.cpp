class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> triplets;
        int i = 0;
        while(i < n) {
            int a = nums[i];
            int lo = i+1;
            int hi = n-1;
            int req = -a;
            while(lo < hi) {
                if(nums[lo] + nums[hi] < req)
                    lo++;
                else if(nums[lo] + nums[hi] > req)
                    hi--;
                else {
                    int b = nums[lo], c = nums[hi];
                    triplets.push_back({a, b, c});
                    while(lo < n && nums[lo] == b) lo++;
                    while(hi > i && nums[hi] == c) hi--;
                }
            }
            while(i < n && nums[i] == a) i++;
        }
        return triplets;
    }
};