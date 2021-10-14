// Step - 1: Recursion (TLE)
/*
class Solution {
public:
    int helper(vector<int> &stoneValue, int start) {
        int n = stoneValue.size();
        if(start >= n) 
            return 0;
        
        int ans = INT_MIN;
        ans = max(ans, stoneValue[start] - helper(stoneValue, start+1));
        
        if(start+1 < n)
            ans = max(ans, stoneValue[start] + stoneValue[start+1] - helper(stoneValue, start+2));
        
        if(start+2 < n)
            ans = max(ans, stoneValue[start] + stoneValue[start+1] + stoneValue[start+2] - helper(stoneValue, start+3));
        
        return ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int res = helper(stoneValue, 0);
        if(res > 0) return "Alice";
        else if(res == 0) return "Tie";
        return "Bob";
    }
};
*/
// Step - 2: Recursion + memoization (DP)
// TC - O(N) + SC - O(N)
class Solution {
public:
    int helper(vector<int> &stoneValue, int start, vector<int> &dp) {
        int n = stoneValue.size();
        if(start >= n) 
            return 0;
        
        // if already computed
        if(dp[start] != -1)
            return dp[start];
        
        int ans = INT_MIN;
        ans = max(ans, stoneValue[start] - helper(stoneValue, start+1, dp));
        
        if(start+1 < n)
            ans = max(ans, stoneValue[start] + stoneValue[start+1] - helper(stoneValue, start+2, dp));
        
        if(start+2 < n)
            ans = max(ans, stoneValue[start] + stoneValue[start+1] + stoneValue[start+2] - helper(stoneValue, start+3, dp));
        
        return dp[start] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, -1);
        int res = helper(stoneValue, 0, dp);
        if(res > 0) return "Alice";
        else if(res == 0) return "Tie";
        return "Bob";
    }
};

