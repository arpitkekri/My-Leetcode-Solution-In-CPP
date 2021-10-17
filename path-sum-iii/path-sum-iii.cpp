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

// Include - Exclude method....
class Solution {
public:
    int helper(TreeNode *root, int sum) {
        if(!root) 
            return 0;
        int res = 0;
        if(root -> val == sum) res++;
        res += helper(root -> left, sum-root->val);
        res += helper(root -> right, sum - root -> val);
        return res;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return pathSum(root->left, targetSum) + pathSum(root->right, targetSum) + helper(root, targetSum);
    }
};