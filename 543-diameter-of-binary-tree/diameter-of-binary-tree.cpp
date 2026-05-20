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
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        int x = maxdiameter(root , dia);
        return dia;
    }
    int maxdiameter(TreeNode* root , int &dia){
        if(root == NULL ){
            return 0;
        }
        int lh = maxdiameter(root->left , dia);
        int rh = maxdiameter(root->right , dia);
        int y = lh + rh ;
        dia = max(dia , y);
        return 1+ max(lh,rh);
    }
};