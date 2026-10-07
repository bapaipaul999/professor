class Solution {
public:
    vector<vector<int>> ans;

    void f(TreeNode* root, int &sum, int &targetSum, vector<int>& temp) {

        if (root == NULL)
            return;

        // Add current node
        temp.push_back(root->val);
        sum += root->val;

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum) {
                ans.push_back(temp);
            }
        }

        // Go left
        if (root->left != NULL) {
            f(root->left, sum, targetSum, temp);
        }

        // Go right
        if (root->right != NULL) {
            f(root->right, sum, targetSum, temp);
        }

        // Backtrack
        temp.pop_back();
        sum -= root->val;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        int sum = 0;

        f(root, sum, targetSum, temp);

        return ans;
    }
};