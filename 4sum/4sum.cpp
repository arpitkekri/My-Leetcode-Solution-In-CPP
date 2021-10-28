class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> quadruplets;
        int i = 0;
        while(i < n-3) {
            int a = nums[i];
            int j = i+1;
            while(j < n-2) {
                int b = nums[j];
                
                int req = target-a-b;
                int lo = j+1, hi = n-1;
                
                while(lo < hi) {
                    if(nums[lo] + nums[hi] < req)
                        lo++;
                    else if(nums[lo] + nums[hi] > req)
                        hi--;
                    else {
                        quadruplets.push_back({a, b, nums[lo], nums[hi]});
                        
                        while(lo < hi && nums[lo] == nums[lo+1]) lo++;
                        while(lo < hi && nums[hi] == nums[hi-1]) hi--;
                        
                        lo++; hi--;
                    }
                }
                
                while(j < n-2 && nums[j] == b) j++;
            }
            while(i < n-3 && nums[i] == a) i++;   
        }
        return quadruplets;
    }
};