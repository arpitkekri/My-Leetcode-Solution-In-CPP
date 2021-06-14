// TC - O(m^3*n)
// SC - O(n*m)
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> rowSum(n, vector<int>(m+1, 0));
        for(int i = 0; i < n; i++)
            for(int j = 1; j <= m; j++)
                rowSum[i][j] = rowSum[i][j-1] + grid[i][j-1];
        
        vector<vector<int>> columnSum(n+1, vector<int>(m, 0));
        for(int j = 0; j < m; j++) 
            for(int i = 1; i <= n; i++)
                columnSum[i][j] = columnSum[i-1][j] + grid[i-1][j];
        
        int maxSz = min(n, m);
        int res = 1;
        
        for(int sz = 2; sz <= maxSz; sz++) {
            for(int i = 0; i <= n-sz; i++) {
                for(int j = 0; j <= m-sz; j++) {
                    int rowkasum = rowSum[i][j+sz] - rowSum[i][j];
                    int flag = 0;
                    for(int k = i+1; k < i+sz; k++) {
                        if((rowSum[k][j+sz] - rowSum[k][j]) != rowkasum) {
                            flag = 1;
                            break;
                        }
                    }
                    if(flag) continue;
                    int columnkasum = columnSum[i+sz][j] - columnSum[i][j];
                    for(int k = j+1; k < j+sz; k++) {
                        if((columnSum[i+sz][k] - columnSum[i][k]) != columnkasum) {
                            flag = 1;
                            break;
                        }
                    }
                    if(flag) continue;
                    if(rowkasum != columnkasum) continue;
                    int firstDiaSum = 0, secondDiaSum = 0;
                    
                    for(int k = 0; k < sz; k++) {
                        firstDiaSum += grid[i+k][j+k];
                        secondDiaSum += grid[i+sz-1-k][j+k];
                    }
                    if(firstDiaSum != secondDiaSum) continue;
                    if(firstDiaSum != rowkasum) continue;
                    res = sz;
                }
            } 
        }
        return res;       
    }
};