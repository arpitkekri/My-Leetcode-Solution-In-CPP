/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        bool isRev = false;
        while(!q.empty()) {
            int n = q.size();
            res.push_back(vector<int>(n));
            for(int i = 0; i < n; i++) {
                TreeNode *temp = q.front();
                q.pop();
                int idx = isRev? n-1-i: i;
                res[res.size()-1][idx] = temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            isRev = !isRev;
        }
        return res;
    }
};