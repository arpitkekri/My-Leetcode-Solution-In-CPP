// class Solution {
// public:
//     int numTrees(int n) {
//         vector<int> dp(n+1, 0);
//         dp[0] = 1, dp[1] = 1;
//         for(int i = 2; i <= n; i++) {
//             for(int j = 0; j < i; j++) {
//                 dp[i] += dp[j]*dp[i-j-1];
//             }
//         }
//         return dp[n];
//     }
// };



// USING catlan number Cn+1/Cn = 2*(2*n+1)/n+2;
/*class Solution {
public:
    int numTrees(int n) {
        vector<long> dp(2, 0);
        dp[0] = 1, dp[1] = 1;
        for(int i = 1; i < n; i++) {
            dp[(i+1)%2] = dp[i%2]*2*(2*i+1)/(i+2);
        }
        return dp[n%2];
    }
};*/

class Solution {
public:
    int numTrees(int n) {
        long c = 1;
        for(int i = 1; i < n; i++) {
            c = c*2*(2*i+1)/(i+2);
        }
        return c;
    }
};