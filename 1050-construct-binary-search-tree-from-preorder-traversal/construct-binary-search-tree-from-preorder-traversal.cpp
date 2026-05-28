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
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        TreeNode* root = new TreeNode(preorder[0]);

        for (int i = 1; i < preorder.size(); i++) {

            TreeNode* curr = root;
            TreeNode* prev = NULL;

            while (curr != NULL) {
                prev = curr;

                if (preorder[i] < curr->val) {
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
            }

            if (preorder[i] < prev->val) {
                prev->left = new TreeNode(preorder[i]);
            } else {
                prev->right = new TreeNode(preorder[i]);
            }
        }

        return root;
    }
};