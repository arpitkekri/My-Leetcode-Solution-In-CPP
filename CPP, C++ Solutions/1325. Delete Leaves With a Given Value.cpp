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
// TC - O(N)
// SC - O(1)
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // Base cases
        if(!root) return NULL;
        
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        
        if(!root->left && !root->right) {
            if(root->val == target) return NULL;
            else return root;
        }
        return root;
    }
};