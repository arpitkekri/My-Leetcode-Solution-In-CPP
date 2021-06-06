/******************** Method-1 (Bottom-Up TC-O(N), SC-O(N)) ***************
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = INT_MIN;
        vector<int> minProd(n+1, 1);
        vector<int> maxProd(n+1, 1);
        
        for(int i = 1; i <= n; i++) {
            minProd[i] = min(nums[i-1], min(nums[i-1]*minProd[i-1], nums[i-1]*maxProd[i-1]));
            maxProd[i] = max(nums[i-1], max(nums[i-1]*minProd[i-1], nums[i-1]*maxProd[i-1]));
            res = max(res, maxProd[i]);
        }
        return res;
    }
};
**************************************************************************************/


/****************** Method-2 (Bottom-Up TC-O(N), SC-O(1)) *****************************/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = INT_MIN;
        int prev_min = 1, prev_max = 1, curr_min, curr_max;
        
        for(int i = 1; i <= n; i++) {
            curr_min = min(nums[i-1], min(nums[i-1]*prev_min, nums[i-1]*prev_max));
            curr_max = max(nums[i-1], max(nums[i-1]*prev_min, nums[i-1]*prev_max));
            res = max(res, curr_max);
            prev_min = curr_min;
            prev_max = curr_max;
        }
        return res;
    }
};