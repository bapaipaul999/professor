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
    vector<TreeNode*> inorder;

    void Inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        Inorder(root->left);
        inorder.push_back(root);
        Inorder(root->right);
    }

    void find(TreeNode* root,
              int maxi,
              int mini,
              int& x) {

        if (root == NULL) {
            return;
        }

        int y = max(abs(maxi - root->val),
                    abs(mini - root->val));

        x = max(x, y);

        maxi = max(maxi, root->val);
        mini = min(mini, root->val);

        find(root->left, maxi, mini, x);
        find(root->right, maxi, mini, x);
    }

    int maxAncestorDiff(TreeNode* root) {

        Inorder(root);

        int x = 0;

        for (int i = 0; i < inorder.size(); i++) {

            find(inorder[i],
                 inorder[i]->val,
                 inorder[i]->val,
                 x);
        }

        return x;
    }
};