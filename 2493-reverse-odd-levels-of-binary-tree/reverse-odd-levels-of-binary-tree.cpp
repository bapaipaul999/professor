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
    TreeNode* reverseOddLevels(TreeNode* root) {

        vector<vector<int>> ans;
        vector<TreeNode*> ans1;

        queue<TreeNode*> q1;
        q1.push(root);

        int level1 = 0;

        while (!q1.empty()) {

            int size = q1.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {

                TreeNode* node = q1.front();
                q1.pop();

                if (level1 % 2 == 1) {

                    int index = size - i - 1;
                    level[index] = node->val;

                    ans1.push_back(node);
                }

                if (node->left != NULL) {
                    q1.push(node->left);
                }

                if (node->right != NULL) {
                    q1.push(node->right);
                }
            }

            if (level1 % 2 == 1) {
                ans.push_back(level);
            }

            level1++;
        }

        int x = 0;

        for (int i = 0; i < ans.size(); i++) {

            for (int j = 0; j < ans[i].size(); j++) {

                ans1[x]->val = ans[i][j];
                x++;
            }
        }

        return root;
    }
};