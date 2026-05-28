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
    vector<int>ans;
    int i = 0;
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    void inorderFix(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorderFix(root->left);
        root->val=ans[i];;
        i++;
        inorderFix(root->right);
    }
    TreeNode* bstToGst(TreeNode* root) {
        inorder(root);
        int sum = 0;
        for(int i = ans.size()-1 ; i>=0 ; i--){
            sum = sum+ans[i];
            ans[i]=sum;

        }
        inorderFix(root);
        return root;
    }
};