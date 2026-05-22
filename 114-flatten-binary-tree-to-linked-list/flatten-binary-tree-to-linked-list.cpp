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
    void inordertrav(TreeNode* root , vector<int> &inorder){
        if (root == NULL){
            return ;
        }
        inorder.push_back(root->val);
        inordertrav(root->left , inorder);
        inordertrav(root->right , inorder);
    }
    void flatten(TreeNode* root) {
        
        vector<int>inorder;
        inordertrav(root , inorder);

        TreeNode* node = root;
        for(int i = 1 ; i<inorder.size() ; i++){
            node -> right = new TreeNode(inorder[i]);
            node->left = NULL;
            node = node->right;
        }
        
    }
};