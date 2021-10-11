class Solution {
public:
    bool dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &safe, int node) {
        visited[node] = true;
        bool res = true;
        for(auto nbr: graph[node]) {
            if(safe[nbr])
                continue;
            if(visited[nbr]) {
                res = false;
                return safe[node] = res;
            }
            
            res = dfs(graph, visited, safe, nbr) && res;
        }
        return safe[node] = res;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<bool> safe(n, false); 
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                bool t = dfs(graph, visited, safe, i);
            }
        }
        vector<int> safenodes;
        for(int i = 0; i < n; i++) {
            if(safe[i]) 
                safenodes.push_back(i);
        }
        return safenodes;
    }
};