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
    long long ans = 0;

    void inorder(TreeNode* root, long long& totalSum) {
        if (root == NULL) {
            return;
        }

        totalSum += root->val;

        inorder(root->left, totalSum);
        inorder(root->right, totalSum);
    }

    long long find(TreeNode* root, long long totalSum) {
        if (root == NULL) {
            return 0;
        }

        long long left = find(root->left, totalSum);
        long long right = find(root->right, totalSum);

        long long subtreeSum = left + right + root->val;

        ans = max(ans, subtreeSum * (totalSum - subtreeSum));

        return subtreeSum;
    }

    int maxProduct(TreeNode* root) {

        long long totalSum = 0;

        inorder(root, totalSum);

        find(root, totalSum);

        return ans % 1000000007;
    }
};