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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int x = maxsum(root , maxi);
        return maxi;
    }
    int maxsum(TreeNode* root , int &maxi){
        if(root == NULL){
            return 0;
        }
        int left_sum = max(0,maxsum(root -> left , maxi));
        int right_sum = max(0,maxsum(root -> right , maxi));
        maxi = max(maxi , root -> val + left_sum + right_sum);
        return root->val+max(left_sum , right_sum);

    }
};