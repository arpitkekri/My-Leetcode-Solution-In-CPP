class Solution {
public:
    int helper(set<int> &s, int curr, int a, int b, int x, bool isBackAllow, vector<vector<int>> &dp) {
        // Base case
        if(curr == x) return 0;
        if(curr < 0 || curr > 6000 || s.find(curr) != s.end())
            return 1e9;
        
        // if exist than return
        if(dp[curr][isBackAllow] != -1)
            return dp[curr][isBackAllow];
        
        // go forward
        dp[curr][isBackAllow] = 1 + helper(s, curr + a, a, b, x, 1, dp);
        
        // go back
        if(isBackAllow) {
            dp[curr][isBackAllow] = min(dp[curr][isBackAllow], 1 + helper(s, curr-b, a, b, x, 0, dp));
        }
        return dp[curr][isBackAllow];
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        if(x == 0) return 0;
        set<int> s(forbidden.begin(), forbidden.end());
        vector<vector<int>> dp(8000, vector<int>(2, -1));
        int res = helper(s, 0, a, b, x, 1, dp);
        if(res > 1e9) return -1;
        return res;
    }
};