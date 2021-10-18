class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        vector<int> answer(n);
        for(int i = 0; i < n; i++)
            answer[i] = i;
        
        for(auto edge: richer) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        
        
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(indegree[i] == 0)
                q.push(i);
        
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            for(auto &nbr: graph[t]) {
                if(quiet[t] < quiet[answer[nbr]]) {
                    answer[nbr] = answer[t];
                    quiet[nbr] = quiet[t];
                }
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        return answer;
    }
};