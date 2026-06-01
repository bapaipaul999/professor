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
    void inorder(TreeNode* root){
        if(root == NULL){
            return ;
        }
        inorder(root->left);
        inorder(root->right);
        if(root->left!=NULL&&root->right!=NULL){
            if((root->left->val == 0 ||root->right->val ==0 )&&root->val == 3){
                root->val = 0;
            }
            else if(root->val == 3){
                root->val = 1;
            }
            else if((root->left->val == 1 ||root->right->val ==1 )&&root->val == 2){
                root->val = 1;
            }
            else if(root->val == 2){
                root->val = 0;
            }
        }

   }
    bool evaluateTree(TreeNode* root) {
        inorder(root);
        return root->val;
    }
};