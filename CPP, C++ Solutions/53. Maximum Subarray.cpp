/*************** Method -1 (kadane's algorithm, TC-O(N), SC-O(1)) **************
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            ans = max(ans, sum);
            if(sum < 0) {
                sum = 0;
            }
        }
        return ans;
    }
};
**********************************************************************/

/******************** Method-2 (Bottom-Up TC-O(N), SC-O(N)) ***************
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), res = INT_MIN;
        vector<int> dp(n+1, 0);
        
        for(int i = 1; i <= n; i++) {
            dp[i] = max(dp[i-1] + nums[i-1], nums[i-1]);
            res = max(res, dp[i]);
        }
        return res;
    }
};
****************************************************************************/

/****************** Method-3 (Bottom-Up TC-O(N), SC-O(1)) *****************************/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), res = INT_MIN;
        int prev = 0, curr;
        
        for(int i = 1; i <= n; i++) {
            curr = max(prev + nums[i-1], nums[i-1]);
            res = max(res, curr);
            prev = curr;
        }
        return res;
    }
};
