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
    void inorder(TreeNode *root, vector<int> &in) {
        if(!root)
            return;
        inorder(root->left, in);
        
        in.push_back(root->val);
        
        inorder(root->right, in);
    }
    
    void recoverTreeHelper(TreeNode* root, int &firstVal, int &secondVal) {
        if(!root) 
            return;
        recoverTreeHelper(root->left, firstVal, secondVal);
        
        if(root->val == firstVal) {
            root -> val = secondVal;
        }
        
        else if(root->val == secondVal) {
            root->val = firstVal;
        }
        
        recoverTreeHelper(root->right, firstVal, secondVal);
    }
    
    void recoverTree(TreeNode* root) {
        vector<int> in;
        inorder(root, in);
        int n = in.size();
        int first = -1, suspect = -1, second = -1;
        for(int i = 0; i < n-1; i++) {
            if(in[i] > in[i+1]) {
                if(first == -1) {
                    first = i;
                    suspect = i+1;
                }
                else {
                    second = i+1;
                }
            }
        }
        
        int firstVal = in[first];
        int secondVal;
        if(second == -1)
            secondVal = in[suspect];
        else secondVal = in[second];
        
        recoverTreeHelper(root, firstVal, secondVal);
        
    }
};

// 2 cases
// 1 2 3 4 5 6 7 8 -> correct

// 1 '7' 3 4 5 6 '2' 8 

// 1 '3' '2' 4 5 6 7 8