class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ptr0 = -1, ptr2 = n;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0 && ptr0 < i) {
                ptr0++;
                swap(nums[i], nums[ptr0]);
                i--;
            }
            else if(nums[i] == 2 && ptr2 > i) {
                ptr2--;
                swap(nums[ptr2], nums[i]);
                i--;
            }
            else continue;
        }
    }
};