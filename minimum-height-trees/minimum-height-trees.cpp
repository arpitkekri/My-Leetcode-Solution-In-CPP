class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        for(auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 1)
                q.push({i, 0});
        }
        int firstMHT = -1, secondMHT = -1, reslevel = -1; 
        while(!q.empty()) {
            pair<int, int> t = q.front();
            q.pop();
            if(t.second > reslevel) {
                reslevel = t.second;
                firstMHT = secondMHT = t.first;
            }
            else if(t.second == reslevel)
                secondMHT = t.first;
            
            for(auto nbr: graph[t.first]) {
                indegree[nbr]--;
                if(indegree[nbr] == 1) 
                    q.push({nbr, t.second+1});
            }
        }
        if(firstMHT == secondMHT) return {firstMHT};
        return {firstMHT, secondMHT};
    }
};