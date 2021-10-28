class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;
        int i = 0;
        while(i < n) {
            int lo = i+1, hi = n-1;
            int a = nums[i];
            while(lo < hi) {
                if(nums[lo] + nums[hi] < -a)
                    lo++;
                else if(nums[lo] + nums[hi] > -a)
                    hi--;
                else {
                    triplets.push_back({a, nums[lo], nums[hi]});
                    
                    while(lo < hi && nums[lo] == nums[lo+1]) lo++;
                    while(lo < hi && nums[hi] == nums[hi-1]) hi--;
                    
                    lo++; hi--;
                }
            }
            while(i < n && nums[i] == a) i++;
        }
        return triplets;
    }
};