class Solution {
public:
    vector<vector<int>> nbrs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int fresh = 0, minutes = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                    grid[i][j] = 0;
                }
                if(grid[i][j] == 1)
                    fresh++;
            }
        }
    
        while(!q.empty()) {
            int sz = q.size();
            int flag = 0;
            for(int i = 0; i < sz; i++) {
                pair<int, int> t = q.front();
                q.pop();
                for(auto nbr: nbrs) {
                    int x = t.first + nbr[0];
                    int y = t.second + nbr[1];

                    if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0)
                        continue;

                    fresh--;
                    flag = 1;
                    grid[x][y] = 0;
                    q.push({x, y});
                }  
            }
            if(flag) minutes++;
        }
        return fresh == 0? minutes: -1;
    }
};