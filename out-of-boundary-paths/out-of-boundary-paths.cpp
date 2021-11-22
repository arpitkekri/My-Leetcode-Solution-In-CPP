class Solution {
private:
    int mod = 1e9 + 7;
    int dp[50][50][51];
    bool isOutOfBound(int x, int y, int m, int n) {
        if(x < 0 || x >= m || y < 0 || y >= n)
            return true;
        return false;
    }
    vector<vector<int>> nbrs = {{0,1}, {1, 0}, {0,-1}, {-1,0}};
public:
    int findPathsHelper(int m, int n, int maxMove, int row, int col) {
        if(maxMove < 0) return 0;
        
        if(isOutOfBound(row, col, m, n))
            return 1;
        
        if(dp[row][col][maxMove] != -1)
            return dp[row][col][maxMove];
        
        int res = 0;
        for(auto &nbr: nbrs) {
            int x = row + nbr[0];
            int y = col + nbr[1];
            res += findPathsHelper(m, n, maxMove-1, x, y);
            res %= mod;
        }
        dp[row][col][maxMove] = res;
        return res;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return findPathsHelper(m, n, maxMove, startRow, startColumn);
    }
};