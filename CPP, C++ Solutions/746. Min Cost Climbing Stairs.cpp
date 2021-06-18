/*********** Method - 1 (Recursion + Memoization, TC - O(N), SC - O(N)) ***************
class Solution {
public:
    int minCostClimbingStairsHelper(vector<int>& cost, int start, vector<int>& dp) {
        // Base case
        if(start < 2) return 0;
        
        // If calculated
        if(dp[start] != -1) 
            return dp[start];
        
        // Recursoive call
        dp[start] = cost[start-1] + minCostClimbingStairsHelper(cost, start-1, dp);
        dp[start] = min(dp[start], cost[start-2] + minCostClimbingStairsHelper(cost, start-2, dp));
        return dp[start];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return minCostClimbingStairsHelper(cost, n, dp);
    }
};
***************************************************************************************/

/******* Method-2 (Bottom-Up, DP, TC-O(N), SC-O(N)) ***********************
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, 0);
        for(int i = 2; i <= n; i++)
            dp[i]  = min(cost[i-1] + dp[i-1], cost[i-2] + dp[i-2]);
        return dp[n];
    }
};
*****************************************************************************/

// Bottom UP DP - Space optimization
// TC-O(N)
// SC-O(1)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(2, 0);
        for(int i = 2; i <= n; i++)
            dp[i%2]  = min(cost[i-1] + dp[(i-1)%2], cost[i-2] + dp[i%2]);
        return dp[n%2];
    }
};