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
        int lh = max(0,maxsum(root -> left,maxi));
        int rh = max(0,maxsum(root -> right,maxi));
        int x = lh+rh+root->val;
        maxi = max(maxi,x);
        return root->val +max(lh,rh);
    }
};