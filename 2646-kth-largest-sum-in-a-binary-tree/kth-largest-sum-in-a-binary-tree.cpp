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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> ans;

        queue<TreeNode*> q1;
        q1.push(root);
        while (!q1.empty()) {
            int size = q1.size();
            long long sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q1.front();
                q1.pop();
                if (node->left != NULL) {
                    q1.push(node->left);
                }
                if (node->right != NULL) {
                    q1.push(node->right);
                }
                sum = sum + node->val;
            }
            ans.push_back(sum);
        }
        sort(ans.begin() , ans.end());
        if(k>ans.size()){
            return -1;
        }
        int x = ans.size() - k;
        return ans[x];
    }
};