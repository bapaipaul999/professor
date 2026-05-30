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
    int deepestLeavesSum(TreeNode* root) {
        vector<int>ans;
        if(root == NULL){
            return 0;
        }
        queue<TreeNode*>q1;
        q1.push(root);
        while(!q1.empty()){
            int size = q1.size();
            int sum = 0;
            for(int i = 0; i<size ; i++){
                TreeNode* node = q1.front();
                q1.pop();
                if(node->left != NULL){
                    q1.push(node->left);
                }
                if(node->right != NULL){
                    q1.push(node->right);
                }
                sum = sum + node->val;
            

            }
            ans.push_back(sum);
        }
        int x = ans.size();

        return ans[x-1];
    }
};