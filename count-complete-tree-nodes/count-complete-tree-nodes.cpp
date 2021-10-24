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
    
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return 1;
        int level = 1;
        TreeNode*temp = root;
        while(temp->left) {
            level++;
            temp = temp->left;
        }
        int totalNode = (1 << (level-1)) - 1;
        
        temp = root;
        int lo = 1, hi = (1 << (level-1));
        
        int tempLevel = 1;
        while(lo < hi) {
            int mid = lo + (hi-lo)/2;
            
            // check mid nodes are present or not
            TreeNode *node = temp -> right;
            int nodeLevel = tempLevel;
            if(node) {
                nodeLevel++;
                while(node->left) {
                    nodeLevel++;
                    node = node->left;
                }
            }
            
            if(nodeLevel == level) {
                lo = mid + 1;
                temp = temp->right;
                tempLevel++;
            }
            else {
                hi = mid;
                temp = temp->left;
                tempLevel++;
            }
        }
        return totalNode + lo;
    }
};