/************* Method - 1 (Top-Down Approach; TC - O(N); SC - O(N)) **********
class Solution {
public:
    // <data-type of ans> f(<Subproblem representation>, <Dp table>)
    int robHelper(vector<int>& nums, int start, vector<int>& dp) {
        int n = nums.size();
        // Base case
        if(start == n-1)
            return nums[n-1];
        
        if(start == n) 
            return 0;
        
        // Checking if already computed
        if(dp[start] != -1)
            return dp[start];
        
        // Recursive Calls
        dp[start] = max(nums[start] + robHelper(nums, start+2, dp), robHelper(nums, start+1, dp));
        return dp[start];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n, -1);
        
        return robHelper(nums, 0, dp);
    }
};
*************************************************************/

/************* Method - 2 (Bottom-Up Approach; TC - O(N); SC - O(N)) **********
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1);
        dp[n] = 0;
        dp[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--)
            dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
        return dp[0];
    }
};
*************************************************************/

/************* Method - 3 (Bottom-Up Approach; TC - O(N); SC - O(1)) **********
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n+1);
        int a = 0, b = nums[n-1], c = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            c = max(nums[i] + a, b);
            a = b;
            b = c;
        }
        return c;
    }
};
*********************************************************************************/

/************* Method - 4 {Shortest Code} (Bottom-Up Approach; TC - O(N); SC - O(1)) **********/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(2, 0);
        dp[(n-1)%2] = nums[n-1];
        for(int i = n-2; i >= 0; i--)
            dp[i%2] = max(nums[i] + dp[i%2], dp[(i+1)%2]);
        return dp[0];
    }
};