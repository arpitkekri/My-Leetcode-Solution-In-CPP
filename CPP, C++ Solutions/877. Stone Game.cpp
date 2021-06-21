/*************** Method-1 (TC - O(N^2),  SC - O(N^2)) *************************
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n =  piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Fill the base case -> primary diagonal
        for(int i = 0; i < n; i++) 
            dp[i][i] = piles[i];
        
        for(int i = n-2; i >= 0; i--)
            for(int j = i+1; j < n; j++)
                dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1]);
                
        return dp[0][n-1] > 0;
    }
};
***************************************************************************/

/************* Method-2 (Optimization of Prev, TC - O(N^2), SC - O(N))
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n =  piles.size();
        vector<int> dp(n, 0);
        
        for(int i = n-1; i >= 0; i--) {
            dp[i] = piles[i];
            for(int j = i+1; j < n; j++)
                dp[j] = max(piles[i] - dp[j], piles[j] - dp[j-1]);
        }

        return dp[n-1] > 0;
    }
};
**************************************************************************/

/************ Method-3 (We want only upper part of matrix so fill only that with Dioganl traversal) ************
// TC -> O(N^1)
// SC -> O(N)

// Diagonal Traversing Implementation
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n =  piles.size();
        vector<int> dp(n);
        
        // Fill the base case -> primary diagonal
        for(int i = 0; i < n; i++) 
            dp[i] = piles[i];
        
        int sz = n-1;
        while(sz--)
            for(int i = 0; i <= sz; i++)
                dp[n-1-i] = max(piles[n-1-i] + dp[n-1-i], piles[sz-i] + dp[n-1-i-1]);   
        
        return dp[n-1] > 0;
    }
};
******************************************************************************************/

// ####### ALL ABOUVE METHOD WITH O(N^2) TIME IS WORK FOR BOTH EVEN OR ODD NUMBER OF PILES ####
// FOR only even number of piles O(1) solution 

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};