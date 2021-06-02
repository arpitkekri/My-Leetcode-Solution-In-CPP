/************* Method - 1 (Top-Down Approach; TC - O(N); SC - O(N)) **********
class Solution {
public:
    // Returns the number of ways you can climb to top
    int climbStairsHelper(int n, vector<int> &dp) {
        // Base case
        if(n == 1)
            return 1;
        
        if(n == 2) 
            return 2;
        
        // Recursive step
        // Have I solved the subproblem?
        if(dp[n] != -1) 
            return dp[n];   
        
        // If I haven't solved it.
        // Solve it now and store it
        dp[n] = climbStairsHelper(n-1, dp) + climbStairsHelper(n-2, dp);
        
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        
        return climbStairsHelper(n, dp);
    }
};
********************************************************************/


/************* Method - 2 (Bottom-Up Approach; TC - O(N); SC - O(N)) **********
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        
        vector<int> dp(n+1);
        
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3; i <= n; i++)
            dp[i] = dp[i-1] + dp[i-2];
        
        return dp[n];
    }
};
*******************************************************************************/


/************* Method - 3 (Bottom-Up Approach; TC - O(N); SC - O(1)) **********/
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        
        vector<int> dp(2);
        
        dp[1%2] = 1;
        dp[2%2] = 2;
        
        for(int i = 3; i <= n; i++)
            dp[i%2] = dp[(i-1)%2] + dp[(i-2)%2];
        
        return dp[n%2];
    }
};