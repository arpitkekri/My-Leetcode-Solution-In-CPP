class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxElt = INT_MIN, sum = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum < 0) sum = 0;
            ans = max(ans, sum);
            maxElt = max(maxElt, nums[i]);
        }
        if(maxElt >= 0) return ans;
        else return maxElt;
    }
};