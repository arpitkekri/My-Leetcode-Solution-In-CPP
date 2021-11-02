class Solution {
public:
    vector<vector<int>> nbrs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int dfs(vector<vector<int>> &grid, pair<int, int> node, int &zeroCount) {
        
        if(grid[node.first][node.second] == 2)
            return zeroCount == 0? 1 : 0;
        
        zeroCount--;
        grid[node.first][node.second] = -1;
        int result = 0;
        
        for(auto nbr: nbrs) {
            int x = node.first + nbr[0];
            int y = node.second + nbr[1];
            
            if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1) 
                continue;
            
            result += dfs(grid, {x, y}, zeroCount);
        }
        zeroCount++;
        grid[node.first][node.second] = 0;
        return result;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        pair<int, int> node;
        int zeroCount = 1;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0)
                    zeroCount++;
                
                if(grid[i][j] == 1)
                    node = make_pair(i, j);
            }
        }
        
        return dfs(grid, node, zeroCount);
    }
};