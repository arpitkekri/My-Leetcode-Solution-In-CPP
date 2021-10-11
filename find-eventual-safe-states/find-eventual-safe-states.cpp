class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> safe(n, false); 
        
        queue<int> q;
        vector<set<int>> g(n), rg(n);
        for(int i = 0; i < n; i++) {
            if(graph[i].size() == 0)
                q.push(i);
            for(int nbr: graph[i]) {
                g[i].insert(nbr);
                rg[nbr].insert(i);
            }
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;
            for(int nbr: rg[node]) {
                g[nbr].erase(node);
                if(g[nbr].empty())
                    q.push(nbr);
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