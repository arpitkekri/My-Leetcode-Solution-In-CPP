class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return;
        int i;
        for(i = n-2; i >= 0; i--)
            if(nums[i] < nums[i+1])
                break;
        if(i < 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        int pos = i;
        for(i = n-1; i >= 0; i--)
            if(nums[i] > nums[pos])
                break;
        swap(nums[i], nums[pos]);
        reverse(nums.begin()+pos+1, nums.end());
    }
};