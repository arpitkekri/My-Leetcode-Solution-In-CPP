// TC - O(n)
// SC - O(1)
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        
        bool isSame = (mat==target);
        if(isSame) return true;
        
        int rotation = 3;
        while(rotation--) {
            
            // Find transpose of mat
            for(int i = 0; i < n; i++)
                for(int j = 0; j < i; j++)
                    swap(mat[i][j], mat[j][i]);
            
            // Reverse every row to get 90 degree rotation
            for(int i = 0; i < n; i++) {
                int start = 0, end = n-1;
                while(start < end)
                    swap(mat[i][start++], mat[i][end--]);
            }
            
            if(mat==target) return true;
        }
        
        return false;
    }
};