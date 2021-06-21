// TC - O(n*m)
// SC - O(n*m)
class Solution {
public:
    bool Helper(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visited, int i, int j) {
        int n = grid1.size();
        int m = grid1[0].size();
        visited[i][j] = true;
        if(grid1[i][j] == 0) return false;
        bool a = true, b = true, c = true, d = true;
        if(j-1 >= 0) {
            if(grid2[i][j-1] == 1 && grid1[i][j-1] == 1 && !visited[i][j-1])
                a = Helper(grid1, grid2, visited, i, j-1);
            if(grid2[i][j-1] == 1 && grid1[i][j-1] == 0) a = false;
        }
        
        if(j+1 < m) {
            if(grid2[i][j+1] == 1 && grid1[i][j+1] == 1 && !visited[i][j+1])
                b = Helper(grid1, grid2, visited, i, j+1);
            if(grid2[i][j+1] == 1 && grid1[i][j+1] == 0) b = false;
        }
        
        if(i-1 >= 0) {
            if(grid2[i-1][j] == 1 && grid1[i-1][j] == 1 && !visited[i-1][j])
                c = Helper(grid1, grid2, visited, i-1, j);
            if(grid2[i-1][j] == 1 && grid1[i-1][j] == 0) c = false;
        }
        
        if(i+1 < n) {
            if(grid2[i+1][j] == 1 && grid1[i+1][j] == 1 && !visited[i+1][j])
                d = Helper(grid1, grid2, visited, i+1, j);
            if(grid2[i+1][j] == 1 && grid1[i+1][j] == 0) d = false;
        }
        return (a && b && c && d);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int res = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!visited[i][j] && grid2[i][j] == 1 && grid1[i][j] == 1) {
                     bool ans = Helper(grid1, grid2, visited, i, j);
                    if(ans) res++;
                }
        return res;
    }
};