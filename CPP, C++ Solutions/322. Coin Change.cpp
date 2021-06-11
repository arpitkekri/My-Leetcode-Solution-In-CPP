/************** Method-1 (BackTracking/Recursion, Gives TLE)
class Solution {
public:
    int coinChangeHelper(vector<int>& coins, int amount, int start) {
        // Base case
        if(amount == 0) return 0;
        if(start == coins.size()) return -1;
        if(amount < coins[start]) return -1;
        
        // Recursive calls
        int a = coinChangeHelper(coins, amount, start+1);
        int b = coinChangeHelper(coins, amount-coins[start], start);
        if(a >= 0 && b >= 0) return min(a, 1+b);
        if(b >= 0) return b+1;
        if(a >= 0) return a;
        return -1;
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        return coinChangeHelper(coins, amount, 0);
    }
};
*******************************************************************/


/******************** Method-2 (Top-Down approach, TC-O(N*amount), SC-O(N*amount)) **************
// Recursion + Memoization
class Solution {
public:
    int coinChangeHelper(vector<int>& coins, int amount, int start, vector<vector<int>>& dp) {
        // Base case
        if(amount == 0) return 0;
        if(start == coins.size()) return -1;
        if(amount < coins[start]) return -1;
        
        // Recursive calls
        if(dp[start+1][amount] == -2)  
            dp[start+1][amount] = coinChangeHelper(coins, amount, start+1, dp);
        
        if(dp[start][amount-coins[start]] == -2)
            dp[start][amount-coins[start]] = coinChangeHelper(coins, amount-coins[start], start, dp);
        
        int a = dp[start+1][amount];
        int b = dp[start][amount-coins[start]];
        if(a >= 0 && b >= 0) dp[start][amount] = min(a, 1+b);
        else if(b >= 0) dp[start][amount] = b+1;
        else if(a >= 0) dp[start][amount] = a;
        else dp[start][amount] = -1;
        return dp[start][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -2));
        dp[0][amount] = coinChangeHelper(coins, amount, 0, dp);
        return dp[0][amount];
    }
};
**********************************************************************************************/


/********************** Method-3 (Bottom Up, TC-O(n*amount), SC-O(n*amount)) *****************
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, INT_MAX));
        dp[n][0] = 0;
        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j <= amount; j++) {
                dp[i][j] = dp[i+1][j];
                
                if(j-coins[i] >= 0 && dp[i][j-coins[i]] != INT_MAX) {
                    dp[i][j] = min(dp[i][j], 1+dp[i][j-coins[i]]);
                }
            }
        }
        return dp[0][amount] == INT_MAX? -1: dp[0][amount];
    }
};
**********************************************************************************************/


/********************** Method-4 (Bottom Up, TC-O(n*amount), SC-O(amount)) *****************
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(2, vector<int>(amount+1, INT_MAX));
        dp[n%2][0] = 0;
        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j <= amount; j++) {
                dp[i%2][j] = dp[(i+1)%2][j];
                if(j-coins[i] >= 0 && dp[i%2][j-coins[i]] != INT_MAX) {
                    dp[i%2][j] = min(dp[i%2][j], 1+dp[i%2][j-coins[i]]);
                }
            }
        }
        return dp[0][amount] == INT_MAX? -1: dp[0][amount];
    }
};
******************************************************************************************/


/****************** Method-5 (Bottom-Up, TC-O(n*amount), SC-O(amount)) *****************
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    // For small optimization sort in reverse order
        sort(coins.begin(), coins.end(), greater<int>() );
        int n = coins.size();
        
        vector<int> dp(amount+1, INT_MAX);
        
        // Base case
        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < n; j++) {
                if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX)
                    dp[i] = min(dp[i], 1+dp[i-coins[j]]);
            }
        }
        
        return dp[amount] == INT_MAX? -1: dp[amount];
    }
};
*****************************************************************************************/
    
// Method -6 optimize approach 4 

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, INT_MAX);
        
        dp[0] = 0;
        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j <= amount; j++) {
                if(j-coins[i] >= 0 && dp[j-coins[i]] != INT_MAX) {
                    dp[j] = min(dp[j], 1+dp[j-coins[i]]);
                }
            }
        }
        return dp[amount] == INT_MAX? -1: dp[amount];
    }
};