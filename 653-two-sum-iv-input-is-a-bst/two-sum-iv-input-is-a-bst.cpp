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
    vector<int>inorder;
    set<int>s1;
    void Inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        Inorder(root->left);
        inorder.push_back(root->val);
        s1.insert(root->val);
        Inorder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        Inorder(root);
        for(int i = 0; i<inorder.size() ; i++){
            
            if(s1.find(k-inorder[i])!=s1.end()&&k-inorder[i]!=k/2){
                return true;
            }
        }
        return false;
    }
};