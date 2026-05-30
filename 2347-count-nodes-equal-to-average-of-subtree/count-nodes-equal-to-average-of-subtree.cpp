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
    vector<TreeNode*>ans;
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        ans.push_back(root);
        inorder(root->right);
        
    }
    void calculate(TreeNode* root , int &sum , int &count){
        if(root == NULL){
            return;
        }
        count++;
        sum = sum + root->val;
        calculate(root->left,sum,count);
        calculate(root->right,sum,count);
    }
    int averageOfSubtree(TreeNode* root) {
        inorder(root);
        int total = 0;
        for(int i = 0; i<ans.size() ; i++){
            int sum = 0;
            int count = 0;
            calculate(ans[i] , sum , count);
            if(sum/count == ans[i]->val){
                total++;
            }
        }
        return total;
    }
};