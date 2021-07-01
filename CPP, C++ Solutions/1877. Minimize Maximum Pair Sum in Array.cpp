// TC - O(NlogN)
// SC - O(1) but if consider sorting also than O(N)
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = n-1;
        int max_sum = 0;
        while(i < j)
            max_sum = max(max_sum, nums[i++] + nums[j--]);
        return max_sum;
    }
};