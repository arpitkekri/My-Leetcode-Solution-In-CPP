class Solution {
public:
    void dfs(unordered_map<char, vector<char>> &graph, char start, vector<int> &visited, int label) {
        visited[start-'a'] = label;
        
        for(auto &nbr: graph[start])
            if(visited[nbr-'a'] == -1)
                dfs(graph, nbr, visited, label);
    }
    
    bool equationsPossible(vector<string>& equations) {
        // Step-1: Construct Graph
        // Adjacency list or graph of charecters 
        unordered_map<char, vector<char>> graph;
        
        for(int i = 0; i < equations.size(); i++) {
            if(equations[i][0] == equations[i][3]) {
                if(equations[i][1] == '!')
                    return false;
                continue;
            }
            
            if(equations[i][1] == '=') {
                graph[equations[i][0]].push_back(equations[i][3]);
                graph[equations[i][3]].push_back(equations[i][0]);
            }
        }
        
        int label = 0;
        vector<int> visited(26, -1);
        for(auto &node: graph) {
            if(visited[node.first-'a'] == -1) {
                dfs(graph, node.first, visited, label);
                label++;
            }
        }
        
        // Process Inequality
        for(int i = 0; i < equations.size(); i++)
            if(equations[i][1] == '!')
                if(visited[equations[i][0]-'a'] == visited[equations[i][3]-'a'] && 
                   visited[equations[i][0]-'a'] != -1 && visited[equations[i][3]-'a'] != -1)
                    return false;
            
        return true;
    }
};