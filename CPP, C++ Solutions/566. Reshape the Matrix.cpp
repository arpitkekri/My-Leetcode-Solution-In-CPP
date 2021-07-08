// TC - O(MN)
// SC - O(RC)
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        // loop through 0 to mn-1 with i = num/n, j = num%n
        int m = mat.size();
        int n = mat[0].size();
        int o = m*n;
        if(r*c != m*n) return mat;
        if(r == m) return mat;
        vector<vector<int>> res(r, vector<int>(c));
        for(int num  = 0; num < o; num++)
            res[num/c][num%c] = mat[num/n][num%n];
        
        return res;
    }
};