/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* start, unordered_map<Node*, Node*> &m) {
        Node* new_node = new Node(start->val);
        m[start] = new_node;
        
        // Visit all the neighbors
        for(auto &nbr: start->neighbors) {
            if(m.find(nbr) == m.end()) 
                dfs(nbr, m);
            new_node->neighbors.push_back(m[nbr]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        
        unordered_map<Node*, Node*> m;
        
        dfs(node, m);
        
        return m[node];
    }
};