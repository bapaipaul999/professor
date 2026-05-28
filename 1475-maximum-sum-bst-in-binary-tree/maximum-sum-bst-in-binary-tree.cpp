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
    int maxi = 0;

    vector<int> solve(TreeNode* root) {
        if (root == NULL) {
            return {1, INT_MAX, INT_MIN, 0};
        }

        auto left = solve(root->left);
        auto right = solve(root->right);

        bool isBST =
            left[0] &&
            right[0] &&
            left[2] < root->val &&
            root->val < right[1];

        if (!isBST) {
            return {0, INT_MIN, INT_MAX, 0};
        }

        int sum =
            left[3] +
            right[3] +
            root->val;

        maxi = max(maxi, sum);

        int mini = min(root->val, left[1]);
        int maxiVal = max(root->val, right[2]);

        return {1, mini, maxiVal, sum};
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return maxi;
    }
};