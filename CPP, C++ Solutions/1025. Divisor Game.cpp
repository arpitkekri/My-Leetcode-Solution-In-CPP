/********** Method-1 (N^2 algo, O(N) space, DP)***********
class Solution {
public:
    bool divisorGame(int n) {
        if(n == 1) return false;
        vector<bool> dp(n+1, false);
        dp[2] = true;
        for(int i = 3; i <= n; i++) {
            bool check = true;
            for(int j = 1; j < i; j++) {
                if(i%(i-j) == 0) {
                    check = check && dp[j];
                }
            }
            if(check) dp[i] = false;
            else dp[i] = true;
        }
        return dp[n];
    }
};
****************************************************************/

// Simple Math
// TC = SC = O(1)
class Solution {
public:
    bool divisorGame(int n) {
        return n%2==0;
    }
};