// TC : O(9^(n*n)) but with pruning
// TC: but we have some filled also so TC: O(9^m) : m = # of unfilled cells
// SC : O(n^2)
class Solution {
public:
    bool solveSudokuHelper(vector<vector<char>>& board, vector<vector<bool>>& row, vector<vector<bool>>& column, vector<vector<bool>>& cell, int i, int j) {
        // Base cases
        if(i == 9)
            return true;
        
        // Recursive case
        
        int copy_i = i, copy_j = j;
        if(j == 8) {copy_j = 0; copy_i = i+1;}
        else copy_j = j + 1;
        
        if(board[i][j] == '.') {
            for(int k = 1; k <= 9; k++) {
                if(!row[i][k] && !column[j][k] && !cell[(i/3)*3 + (j/3)][k]) {
                    
                    board[i][j] = '0' + k;
                    row[i][k] = true;
                    column[j][k] = true;
                    cell[(i/3)*3 + (j/3)][k] = true;
                    
                    bool b = solveSudokuHelper(board, row, column, cell, copy_i, copy_j);
                    if(b) return true;
                    
                    board[i][j] = '.';
                    row[i][k] = false;
                    column[j][k] = false;
                    cell[(i/3)*3 + (j/3)][k] = false;
                }
            }
        }
        else {
            bool b1 = solveSudokuHelper(board, row, column, cell, copy_i, copy_j);
            if(b1) return true;
        }
        return false;
}
    void solveSudoku(vector<vector<char>>& board) {
        
        vector<vector<bool>> row(9, vector<bool>(10, false));
        vector<vector<bool>> column(9, vector<bool>(10, false));
        vector<vector<bool>> cell(9, vector<bool>(10, false));
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int digit = board[i][j] - '0';
                    row[i][digit] = true;
                    column[j][digit] = true;
                    
                    // compute cell number from i and j
                    // cell no. = (i/3)*3 + (j/3)
                    cell[(i/3)*3 + (j/3)][digit] = true;
                }
            }
        }
        
        // Call the helper function
        solveSudokuHelper(board, row, column, cell, 0, 0);
    }
};