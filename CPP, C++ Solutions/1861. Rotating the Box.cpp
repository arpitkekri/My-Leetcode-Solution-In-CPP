// TC - O(N^2)
// SC - O(N^2)
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        vector<vector<char>> res(m, vector<char>(n, '.'));
        
        for(int k = 0; k < n; k++) {
            int i = m;
            while(i--)
                if(box[k][i] == '.') break;
            
            int j = i-1;
            while(j >= 0 && i >= 0) {
                if(box[k][j] == '*') i = j-1;
                else if(box[k][j] == '#') swap(box[k][j], box[k][i--]);
                j--;
            }
            
            for(int l = 0; l < m; l++)
                res[l][n-1-k] = box[k][l];
        }
        
        return res;
    }
};