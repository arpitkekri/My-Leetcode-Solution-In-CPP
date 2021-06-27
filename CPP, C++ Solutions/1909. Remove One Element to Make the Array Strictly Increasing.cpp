class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int count = 0;
        if(nums[0] >= nums[1]) {
            prev = nums[1];
            count = 1;
        }
        for(int i = 1; i < n; i++) {
            if(count == 1 && i == 1) continue;
            if(nums[i] <= prev) {
                count++;
                if(count == 2) return false;
                if(i + 1 < n) {
                    if(nums[i+1] > prev) continue;
                    else {
                        prev = nums[i-2];
                        i--;
                    }
                }
            }
            else prev = nums[i];
        }
        return true;
    }
};