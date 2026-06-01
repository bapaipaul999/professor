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
    void inorder(TreeNode* root ,int x, bool &y){
        if(root==NULL){
            return;
        }
        if(root->val!=x){
            y = false;
        }
        inorder(root->left,x,y);
        inorder(root->right,x,y);
    }
    bool isUnivalTree(TreeNode* root) {
        int x = root->val;
        bool y = true;
        inorder(root, x,y);
        return y;
    }
};