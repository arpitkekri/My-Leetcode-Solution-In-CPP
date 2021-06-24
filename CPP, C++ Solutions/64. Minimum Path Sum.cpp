/*********** Method-1(TC - O(NM), SC - O(NM)) **************************************
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(min(dp[i+1][j], dp[i][j+1]) == INT_MAX) 
                    dp[i][j] = grid[i][j];
                else 
                    dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};
***********************************************************************************/


/**********************Method-2 (TC-O(NM), SC-O(N))**************************************/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<int> dp(n+1, INT_MAX);
        
        // Base case
        dp[n-1] = 0;
        
        // Bottom to Top, R to L
        for(int i = m-1; i >= 0; i--)
            for(int j = n-1; j >= 0; j--)
                dp[j] = grid[i][j] + min(dp[j], dp[j+1]);
        
        return dp[0];
    }
};