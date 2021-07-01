// TC - O(n^4)
// SC - O(n)
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int max_size = (min(m, n)+1)/2;
        set<int> all;
        for(int sz = 1; sz <= max_size; sz++) {
            for(int j = sz-1; j <= n-sz; j++) {
                for(int i = 0; i <= m + 1 -sz*2; i++) {
                    int sum = grid[i][j];
                    int ci = i, cj = j;
                    for(int k = 1; k < sz; k++) {
                        sum += grid[ci+k][cj+k];
                        sum += grid[ci+k][cj-k];
                    }
                    if(2*(sz-1)) {
                        ci = i + sz*2 - 2;
                        cj = j;
                        sum += grid[ci][cj];
                        for(int k = 1; k < sz-1; k++) {
                            sum += grid[ci-k][cj+k];
                            sum += grid[ci-k][cj-k];
                        }
                    }
                    all.insert(sum);
                    if (all.size() > 3)
                        all.erase(begin(all)); 
                }
            }
        }
        return vector<int>(all.rbegin(), all.rend());
    }
};