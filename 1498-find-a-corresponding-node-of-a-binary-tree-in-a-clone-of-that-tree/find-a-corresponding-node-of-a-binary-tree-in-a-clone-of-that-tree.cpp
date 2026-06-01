/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void inorder(TreeNode* root , TreeNode* target , TreeNode* &temp){
        if(root == NULL){
            return;
        }
        if(root->val == target->val){
            temp = root;
        }
        inorder(root->left , target , temp);
        inorder(root->right , target , temp);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* temp = NULL;
        inorder(cloned , target , temp);
        return temp;
    }
};