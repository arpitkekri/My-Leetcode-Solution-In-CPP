class Solution {
public:
    int numLiveNeighbors(vector<vector<int>>& board, int i, int j) {
        int n = board.size();
        int m = board[0].size();
        int ans = 0;
        for(int s = i-1; s <= i+1; s++) {
            for(int e = j-1; e <= j+1; e++) {
                if(s == i && e == j) continue;
                if((s >= 0 && s < n) && (e >= 0 && e < m) && (board[s][e] >= 1)) ans++; 
            }
        }
        return ans;   
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        int neighbour;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 1) {
                    neighbour = numLiveNeighbors(board, i, j);
                    if(neighbour == 2 || neighbour == 3) board[i][j]++;
                }
                else {
                    neighbour = numLiveNeighbors(board, i, j);
                    if(neighbour == 3) board[i][j]--;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == -1 || board[i][j] == 2)
                    board[i][j] = 1;
                else board[i][j] *= 0;
            }
        }
    }
};