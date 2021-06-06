/************* Method-1 (Bottom-Up, TC-O(N), SC-O(N)) *******************
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n+1, vector<int>(3, 0));
        // dp[n-1][0] = costs[n-1][0];
        // dp[n-1][1] = costs[n-1][1];
        // dp[n-1][2] = costs[n-1][2];
        
        for(int i = n-1; i >= 0; i--) {
            dp[i][0] = costs[i][0] + min(dp[i+1][1], dp[i+1][2]);
            dp[i][1] = costs[i][1] + min(dp[i+1][2], dp[i+1][0]);
            dp[i][2] = costs[i][2] + min(dp[i+1][1], dp[i+1][0]);
        }
        return min(dp[0][0], min(dp[0][1], dp[0][2]));
    }
};
****************************************************************************/

/********* Method-2 (Bottom-Up, TC-O(N), SC-O(1)) **************************/
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(2, vector<int>(3, 0));
        
        for(int i = n-1; i >= 0; i--) {
            dp[i%2][0] = costs[i][0] + min(dp[(i+1)%2][1], dp[(i+1)%2][2]);
            dp[i%2][1] = costs[i][1] + min(dp[(i+1)%2][2], dp[(i+1)%2][0]);
            dp[i%2][2] = costs[i][2] + min(dp[(i+1)%2][1], dp[(i+1)%2][0]);
        }
        return min(dp[0][0], min(dp[0][1], dp[0][2]));
    }
};