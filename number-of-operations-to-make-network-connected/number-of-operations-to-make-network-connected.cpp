class Solution {
public:
    int find(int v, vector<int>& parent) {
        if(v == parent[v]) return parent[v];
        return parent[v] = find(parent[v], parent);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        int extra = 0, req = n-1;
        for(auto &edge: connections) {
            int p1 = find(edge[0], parent);
            int p2 = find(edge[1], parent);
            if(p1 == p2) extra++;
            else {
                parent[p1] = p2;
                req--;
            }
        }
        if(extra >= req) return req;
        return -1;
    }
};