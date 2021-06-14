/************** Method-1 (BackTracking/Recursion, TLE) **********************************
class Solution {
public:
    int changeHelper(vector<int>& coins, int start, int amount) {
        // Base cases
        if(amount == 0) return 1;
        if(start == coins.size()) return 0;
        
        // Recursive calls
        if(amount < coins[start]) return changeHelper(coins, start+1, amount);
        return changeHelper(coins, start+1, amount) + changeHelper(coins, start, amount-coins[start]);
    }
    
    int change(int amount, vector<int>& coins) {
        return changeHelper(coins, 0, amount);
    }
};
*********************************************************************************/


/******************** Method-2 (Top-Down approach, TC-O(N*amount), SC-O(N*amount)) **************
class Solution {
public:
    int changeHelper(vector<int>& coins, int start, int amount, vector<vector<int>>& dp) {
        // Base cases
        if(amount == 0) return 1;
        if(start == coins.size()) return 0;
        
        // Check if already computed
        if(dp[start][amount] != -1) return dp[start][amount];
        
        // Recursive calls
        dp[start][amount] = changeHelper(coins, start+1, amount, dp);
        if(amount >= coins[start])
            dp[start][amount] += changeHelper(coins, start, amount-coins[start], dp);
        return dp[start][amount];
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        return changeHelper(coins, 0, amount, dp);
    }
};
*****************************************************************************************/


/********************** Method-3 (Bottom Up, TC-O(n*amount), SC-O(amount)) *************/
class Solution {
  public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        int n = coins.size();
        for(int i = n-1; i >= 0; i--) {
            for(int j = 1; j <= amount; j++) {
                if(j-coins[i] >= 0)
                    dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};