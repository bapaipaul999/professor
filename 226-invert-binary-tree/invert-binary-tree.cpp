/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if (root == NULL) {
            return NULL;
        }

        queue<TreeNode*> q1;
        q1.push(root);

        while (!q1.empty()) {

            TreeNode* node = q1.front();
            q1.pop();

            swap(node->left, node->right);

            if (node->left != NULL) {
                q1.push(node->left);
            }

            if (node->right != NULL) {
                q1.push(node->right);
            }
        }

        return root;
    }
};