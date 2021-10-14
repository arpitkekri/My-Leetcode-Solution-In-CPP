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
/*
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
*/

// Step - 3: Bottom Up DP
// TC - O(N) + SC - O(N)
/*
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n+1, INT_MIN);
        dp[n] = 0;
        
        for(int i = n-1; i >= 0; i--) {
            dp[i] = max(dp[i], stoneValue[i] - dp[i+1]);
            
            if(i + 1 < n)
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i+1] - dp[i+2]);
            
            if(i + 2 < n)
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dp[i+3]);
        }
        
        if(dp[0] > 0) return "Alice";
        else if(dp[0] == 0) return "Tie";
        return "Bob";
    }
};
*/

// Step - 4: Bottom Up DP
// TC - O(N) + SC - O(1)
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(3, INT_MIN);
        dp[n%3] = 0;
        
        for(int i = n-1; i >= 0; i--) {
            int ans = INT_MIN;
            
            ans = max(ans, stoneValue[i] - dp[(i+1)%3]);
    
            if(i + 1 < n)
                ans = max(ans, stoneValue[i] + stoneValue[i+1] - dp[(i+2)%3]);
            
            if(i + 2 < n)
                ans = max(ans, stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dp[i%3]);
            
            dp[i%3] = ans;
        }
        
        if(dp[0] > 0) return "Alice";
        else if(dp[0] == 0) return "Tie";
        return "Bob";
    }
};