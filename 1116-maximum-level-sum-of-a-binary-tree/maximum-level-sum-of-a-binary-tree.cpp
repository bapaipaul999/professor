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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q1;
        q1.push(root);
        int ans = 1;
        int totalSum = INT_MIN;
        int level = 1 ;
        while (!q1.empty()) {
            int size = q1.size();
            int sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q1.front();
                q1.pop();
                sum = sum + temp->val;
                if (temp->left != NULL) {
                    q1.push(temp->left);
                }
                if (temp->right != NULL) {
                    q1.push(temp->right);
                }
            }
            if (sum > totalSum) {
                ans = level;
                totalSum = sum;
            }
            level++;
        }
        return ans;
    }
};