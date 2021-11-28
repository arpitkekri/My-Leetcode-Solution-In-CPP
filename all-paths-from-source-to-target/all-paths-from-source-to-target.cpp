class Solution {
public:
    void dfs(vector<vector<int>> &graph, int node, vector<int> &path, vector<vector<int>> &all_paths) {
int n = graph.size();	
if(node == n-1) {
	path.push_back(node);
	all_paths.push_back(path);
	path.pop_back();
	return;
}
path.push_back(node);
for(int &nbr: graph[node]) {
	dfs(graph, nbr, path, all_paths);
}
path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
int n = graph.size();
vector<vector<int>> all_paths;
vector<int> path;
dfs(graph, 0, path, all_paths);
return all_paths;
}

};