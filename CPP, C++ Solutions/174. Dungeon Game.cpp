/*********** Method-1(TC - O(NM), SC - O(NM)) **************************************
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        
        dp[m-1][n-1] = max(1, 1-dungeon[m-1][n-1]);
        
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--) {
                if(i+1 < m) 
                    dp[i][j] = min(dp[i][j], dp[i+1][j] - dungeon[i][j]);
                
                if(j+1 < n) 
                    dp[i][j] = min(dp[i][j], dp[i][j+1] - dungeon[i][j]);
                
                dp[i][j] = max(1, dp[i][j]);
            }
        }
        return dp[0][0];
    }
};
***********************************************************************************/


/**********************Method-2 (TC-O(NM), SC-O(N))**************************************/
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        
        vector<int>dp(n, INT_MAX);
        
        dp[n-1] = max(1, 1-dungeon[m-1][n-1]);
        
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(i+1 < m)
                    dp[j] = min(INT_MAX, dp[j] - dungeon[i][j]);
                
                if(j+1 < n)
                    dp[j] = min(dp[j], dp[j+1] - dungeon[i][j]);
                
                dp[j] = max(1, dp[j]);
            }
        }
        return dp[0];
    }
};