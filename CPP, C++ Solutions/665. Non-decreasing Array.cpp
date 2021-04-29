class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return true;
        int count = 0, flag = 0;
        int i, j;
        for(i = 0; i < n-1; i++) {
            if(nums[i] > nums[i+1]) break;
        }
        // cout << i << endl;
        if(i == n-1) return true;
        for(j = n-1; j >= 1; j--) {
            if(nums[j] < nums[j-1]) break;
        }
        if(j-i > 1) return false;
        else {
            if(i == 0 || j == n-1) return true;
            else if(nums[i] <= nums[j+1]) return true;
            else if(nums[i-1] <= nums[j]) return true;
            else return false;
        }
    }
};