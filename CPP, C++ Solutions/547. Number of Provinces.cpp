class Solution {
public:
    void dfs(vector<vector<int>> &isConnected,  int start, vector<bool> &visited) {
        visited[start] = true;
        for(int j = 0; j < isConnected.size(); j++)
            if(isConnected[start][j] == 1 && !visited[j])
                dfs(isConnected, j, visited);   
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                count++;
                dfs(isConnected, i, visited);
            }
        }
        return count;
    }
};