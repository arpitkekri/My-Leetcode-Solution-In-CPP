/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return ",";
        string serial = "";
        serial += to_string(root->val) + ",";
        serial += serialize(root->left);
        serial += serialize(root->right);
        return serial;
    }

    TreeNode* preorderDeserialize(stringstream &ss) {
        string val;
        getline(ss, val, ',');
        if(val == "") return NULL;
        TreeNode *root = new TreeNode(stoi(val));
        root -> left = preorderDeserialize(ss);
        root -> right = preorderDeserialize(ss);
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        TreeNode *root = preorderDeserialize(ss);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));