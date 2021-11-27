class Solution {
public:
    
    int findRoot(vector<int> &parent, int x) {
        int curr_node = x;
        
        while(parent[curr_node] != curr_node) {
            curr_node = parent[curr_node];
        }
        
        return curr_node;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, -1);
        
        // Start with an empty set of trees.
        for(int i = 1; i <= n; i++)
            parent[i] = i;
        
        // Add edges one by one.
        for (int i = 0; i < n; i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            
            int root_x = findRoot(parent, x);
            int root_y = findRoot(parent, y);
            
            if(root_x == root_y)
                return edges[i];
            
            parent[root_y] = root_x;
        }
        
        // NF
        return {-1, -1};
    }
};