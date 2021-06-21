// Idea-1 => Reverse the first string and take LIC of both strings
/****** Method-1 (Bottom-Up, TC - O(N^2), SC - O(N^2))
class Solution {
public:
    int lcs(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
    
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return lcs(s, s2);
    }
};
************************************************************************/

/***************** Method-2 (Space Optimization, TC - O(N^2), SC - O(N))**********
class Solution {
public:
    int lcs(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(2, vector<int>(m+1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                
                if(s1[i-1] == s2[j-1])
                    dp[i%2][j] = 1 + dp[(i-1)%2][j-1];
                else 
                    dp[i%2][j] = max(dp[i%2][j-1], dp[(i-1)%2][j]);
            }
        }
        return dp[n%2][m];
    }
    
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return lcs(s, s2);
    }
};
*******************************************************************************/


// ###### IDEA-2 => USE dp[i][j] = max(dp[i+][j], dp[i][j+1]) ->if s[i] != s[j] 
// and if(s[i] == s[j]) dp[i][j] = 2 + dp[i+1][j-1];

/********* Method-3(Diagonal Implementation of Idea 2, TC-O(N^2), SC-O(N^2)) ******
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size(), len, i;
        vector<vector<int>> dp(n, vector<int>(n ,0));
        
        // Length wise
        for(int len = 1; len <= n; len++) {
            for(int i = 0; i+len-1 < n; i++) {
                if(len == 1)
                    dp[i][i] = 1;
                else {
                    if(s[i] == s[i+len-1])
                        dp[i][i+len-1] = 2 + dp[i+1][i+len-2];
                    else 
                        dp[i][i+len-1] = max(dp[i+1][i+len-1], dp[i][i+len-2]);
                }
            }
        }
        return dp[0][n-1];
    }
};
****************************************************************************************/

/************* Method-4(Simple implementation of idea-2, TC-O(N^2), SC-O(N^2))***********
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n ,0));
        
        // Base case -> dp[i][i] = 1;
        for(int i = n-1; i >= 0; i--) {
            dp[i][i] = 1;
            for(int j = i+1; j < n; j++) {
                if(s[i] == s[j])
                    dp[i][j] = 2 + dp[i+1][j-1];
                else 
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};
***************************************************************************************/

/** Method-5 (Oprtimization of abouve method, TC - O(N^2), SC - O(N)) *****************/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(2, vector<int>(n ,0));
        
        for(int i = n-1; i >= 0; i--) {
            dp[i%2][i] = 1;
            for(int j = i+1; j < n; j++) {
                if(s[i] == s[j])
                    dp[i%2][j] = 2 + dp[(i+1)%2][j-1];
                else 
                    dp[i%2][j] = max(dp[(i+1)%2][j], dp[i%2][j-1]);
            }
        }
        return dp[0][n-1];
    }
};