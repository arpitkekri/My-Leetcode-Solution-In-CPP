/************Method-1(Bottom-Up, Gives TLE, TC - O(n^2), SC - O(N^2))***************
class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) 
            return false;
        
        int n = stones.size();
        unordered_map<int, int> m;
        vector<vector<bool>> dp(n, vector<bool>(n+1, false));
        
        // Populate the map and fill the base case
        for(int i = 0; i < n; i++) {
            m[stones[i]] = i; 
            dp[n-1][i+1] = true;
        }
        
        // DP table
        for(int i = n-2; i >= 1; i--) {
            for(int j = 1; j <= n; j++) {
                // 3 cases
                // j-1
                if(j> 1 && m.find(stones[i]+j-1) != m.end()) 
                    dp[i][j] = dp[i][j] || dp[m[stones[i]+j-1]][j-1];
                
                // j
                if(m.find(stones[i]+j) != m.end())
                     dp[i][j] = dp[i][j] || dp[m[stones[i]+j]][j];
                
                // j+1
                if(m.find(stones[i]+j+1) != m.end())
                     dp[i][j] = dp[i][j] || dp[m[stones[i]+j+1]][j+1];
            }
        }
        
        return dp[1][1];
    }
};
******************************************************************************************/


/************Method-1(Top-Down, TC - O(n^2), SC - O(N^2))*********************************/
class Solution {
public:
    int canCrossHelper(unordered_map<int, int>&m, vector<vector<int>> &dp, int i, int j, vector<int> &stones) {
        int n = stones.size();
        // Base case
        if(i == n-1) 
            return 1;
        
        // DP state
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // Recursive call
        int t1 = 0, t2 = 0, t3 = 0;
        // 3 cases
        // j-1
        if(j> 1 && m.find(stones[i]+j-1) != m.end()) 
            t1 =  canCrossHelper(m, dp, m[stones[i]+j-1], j-1, stones);

        // j
        if(m.find(stones[i]+j) != m.end())
             t2 =  canCrossHelper(m, dp, m[stones[i]+j], j, stones);

        // j+1
        if(m.find(stones[i]+j+1) != m.end())
             t3 =  canCrossHelper(m, dp, m[stones[i]+j+1], j+1, stones);
        
        dp[i][j] = t1 || t2 || t3;
        return dp[i][j];
    }
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) 
            return false;
        
        int n = stones.size();
        unordered_map<int, int> m;
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
        // Populate the map
        for(int i = 0; i < n; i++)
            m[stones[i]] = i;
        
        return canCrossHelper(m, dp, 1, 1, stones);
    }
};