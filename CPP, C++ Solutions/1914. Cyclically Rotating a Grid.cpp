class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int level = min(n, m)/2;
        
        for(int l = 0; l < level; l++) {
            int start_i = l, start_j = l;
            int m2 = m - 2*l;
            int n2 = n - 2*l;
            int curr_elt = m2*n2-(m2-2)*(n2-2);
            int r = k%curr_elt;
            vector<int> a;
            int i, j;

            for(i = start_i; i < start_i+m2; i++)
                a.push_back(grid[i][start_j]);
            
            for(int j = start_j+1; j < start_j+n2; j++) 
                a.push_back(grid[start_i+m2-1][j]);
            
            for(i = start_i+m2-2; i >= start_i; i--) 
                a.push_back(grid[i][start_j+n2-1]);
            
            for(j = start_j+n2-2; j > start_j; j--)
                a.push_back(grid[start_i][j]);

            
            int p = curr_elt-r;
            for(i = start_i; i < start_i+m2; i++) {
                grid[i][start_j] = a[p%a.size()];
                p++;
            }
            for(int j = start_j+1; j < start_j+n2; j++) {
                grid[start_i+m2-1][j] = a[p%a.size()];
                p++;
            }
            
            for(i = start_i+m2-2; i >= start_i; i--) {
                grid[i][start_j+n2-1] = a[p%a.size()];
                p++;
            }
            for(j = start_j+n2-2; j > start_j; j--) {
                grid[start_i][j] = a[p%a.size()];
                p++;
            }
        }
        return grid;
    }
};