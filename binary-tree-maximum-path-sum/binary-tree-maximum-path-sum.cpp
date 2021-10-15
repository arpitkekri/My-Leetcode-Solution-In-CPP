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
    int helper(TreeNode* root, int &rooted) {
        if(!root) {
            rooted = INT_MIN;
            return INT_MIN;
        }
        int rLeft, rRight;
        int leftAns = helper(root->left, rLeft);
        int rightAns = helper(root->right, rRight);
        rooted = root->val + max({0, rLeft, rRight});
        return max({leftAns, rightAns, root->val + max(0, rLeft) + max(0, rRight)});
    }
    int maxPathSum(TreeNode* root) {
        int rooted;
        return helper(root, rooted);
    }
};