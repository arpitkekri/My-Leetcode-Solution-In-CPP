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
    TreeNode* helper(vector<int> &preorder, int &pos, int maxLeft, int minRight) {
        if(pos >= preorder.size())
            return NULL;
        
        if(maxLeft > preorder[pos] || preorder[pos] > minRight)
            return NULL;
        
        if(maxLeft < preorder[pos] && preorder[pos] < minRight) {
            TreeNode * root = new TreeNode(preorder[pos]);
            pos++;
            root -> left = helper(preorder, pos, maxLeft, root -> val);
            root -> right = helper(preorder, pos, root -> val, minRight);
            return root;
        }
        return NULL;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int pos = 0;
        return helper(preorder, pos, INT_MIN, INT_MAX);
    }
};