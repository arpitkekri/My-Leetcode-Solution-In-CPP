void dfs(vector<vector<int>> &tree, int node, int par, vector<deque<pair<int,int>>> &ances, vector<int> &ans, vector<int> &arr, int level){
    int currlevel=-1;
    for(int i=1;i<=50;i++){
        if(ances[i].size()){
            if(currlevel<ances[i][0].first && __gcd(arr[ances[i][0].second], arr[node])==1){
                currlevel=ances[i][0].first;
                ans[node]=ances[i][0].second;
            }
        }
    }
    
    ances[arr[node]].push_front(make_pair(level,node));
    
    
    for(int i=0;i<tree[node].size();i++){
        int curr=tree[node][i];
        if(curr!=par)
        dfs(tree, curr, node, ances, ans, arr, level+1);
    }
    
    ances[arr[node]].pop_front();
}


class Solution {
public:
    vector<int> getCoprimes(vector<int>& arr, vector<vector<int>>& edges) {
        int n=arr.size();
        vector<vector<int>> tree(n);
        for(int i=0;i<edges.size();i++){
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<deque<pair<int, int>>> ances(51);
        vector<int> ans(n,-1);
        dfs(tree, 0, -1, ances, ans, arr,0);
        return ans;
    }
};