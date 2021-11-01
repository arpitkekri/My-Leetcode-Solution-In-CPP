class Solution {
public:
    vector<vector<int>> nbrs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0) return;
        int n = board[0].size();
        if(n == 0) return;
        
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') q.push({i, 0});
            if(board[i][n-1] == 'O') q.push({i, n-1});
        }
        for(int j = 1; j < n-1; j++) {
            if(board[0][j] == 'O') q.push({0, j});
            if(board[m-1][j] == 'O') q.push({m-1, j});
        }
        while(!q.empty()) {
            pair<int, int> t = q.front();
            q.pop();
            board[t.first][t.second] = 'P';
            for(auto nbr: nbrs) {
                int x = t.first + nbr[0];
                int y = t.second + nbr[1];
                
                if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] == 'X')
                    continue;
                if(board[x][y] == 'O')
                    q.push({x, y});
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'P')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};