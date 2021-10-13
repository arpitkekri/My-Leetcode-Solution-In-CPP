class Solution {
public:
    int find(int v, vector<int> &parent) {
        if(parent[v] == -1) return v;
        return parent[v] = find(parent[v], parent);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n, -1);
        int p1, p2;
        for(int i = 0; i < n; i++) {
            p1 = find(i, parent);
            if(leftChild[i] != -1) {
                p2 = find(leftChild[i], parent);
                if(p1 == p2)
                    return false;
                parent[leftChild[i]] = i;
        
                // if(parent[leftChild[i]] != -1 && parent[leftChild[i]] != i)
                    // return false;
                // parent[leftChild[i]] = i;
            }
            if(rightChild[i] != -1) {
                // if(parent[rightChild[i]] != -1 && parent[rightChild[i]] != i)
                    // return false;
                // parent[rightChild[i]] = i;
               
                p2 = find(rightChild[i], parent);
                if(p1 == p2)
                    return false;
                parent[rightChild[i]] = i;
            }
        }
        
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(parent[i] == -1) count++;
        }
        return count == 1;
    }
};