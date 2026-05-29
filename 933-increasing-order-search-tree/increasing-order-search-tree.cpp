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
    void inorder(TreeNode* root ){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        TreeNode* root2 = new TreeNode(ans[0]);
        for(int i = 1 ; i<ans.size() ; i++){
            TreeNode* current = root2;
            TreeNode* prev = current;
            while(current!=NULL){
                prev = current;
                if(current->val>ans[i]){
                    current = current -> left;
                }
                else{
                    current = current ->right;
                }
            }
            if(prev->val > ans[i]){
                TreeNode* temp = new TreeNode(ans[i]);
                prev -> left = temp;
            }
            else{
                TreeNode* temp = new TreeNode(ans[i]);
                prev -> right = temp;
            }
        }
        return root2;
    }
};