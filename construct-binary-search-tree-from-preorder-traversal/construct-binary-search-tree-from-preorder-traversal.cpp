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
        if(pos+1 >= preorder.size())
            return NULL;
        
        if(maxLeft > preorder[pos+1] || preorder[pos+1] > minRight)
            return NULL;
        
        if(maxLeft < preorder[pos+1] && preorder[pos+1] < minRight) {
            TreeNode * root = new TreeNode(preorder[pos+1]);
            pos++;
            root -> left = helper(preorder, pos, maxLeft, root -> val);
            root -> right = helper(preorder, pos, root -> val, minRight);
            return root;
        }
        return NULL;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int pos = -1;
        return helper(preorder, pos, INT_MIN, INT_MAX);
    }
};