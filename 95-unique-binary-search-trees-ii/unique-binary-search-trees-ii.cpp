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
    vector<TreeNode*> solve(int start, int end) {

        vector<TreeNode*> ans;

        if (start > end) {
            ans.push_back(NULL);
            return ans;
        }

        for (int root = start; root <= end; root++) {

            vector<TreeNode*> left = solve(start, root - 1);
            vector<TreeNode*> right = solve(root + 1, end);

            for (auto l : left) {
                for (auto r : right) {

                    TreeNode* node = new TreeNode(root);

                    node->left = l;
                    node->right = r;

                    ans.push_back(node);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};