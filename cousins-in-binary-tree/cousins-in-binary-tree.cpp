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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x || root->val == y) return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            bool foundx = false, foundy = false;
            for(int i = 0; i < sz; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && (temp->left->val == x || temp->left->val == y) && 
                   temp->right && (temp->right->val == x || temp->right->val == y))
                    return false;
                
                if(temp->val == x) foundx = true;
                if(temp->val == y) foundy = true;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(foundx && foundy) return true;
            if(foundx || foundy) return false;
        }
        return false;
    }
};