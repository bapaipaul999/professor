class Solution {
public:
    int count = 0;

    // Find paths starting from this node
    void dfs(TreeNode* root, long long sum, int targetSum) {
        if (root == NULL)
            return;

        sum += root->val;

        if (sum == targetSum)
            count++;

        dfs(root->left, sum, targetSum);
        dfs(root->right, sum, targetSum);
    }

    // Make every node a possible starting point
    void f(TreeNode* root, int targetSum) {
        if (root == NULL)
            return;

        dfs(root, 0, targetSum);

        f(root->left, targetSum);
        f(root->right, targetSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        f(root, targetSum);
        return count;
    }
};