/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parents(map<TreeNode*, TreeNode*>& mp,
                 TreeNode* root,
                 TreeNode* parent) {

        if (root == NULL) {
            return;
        }

        mp[root] = parent;

        parents(mp, root->left, root);
        parents(mp, root->right, root);
    }

    vector<int> distanceK(TreeNode* root,
                          TreeNode* target,
                          int k) {

        map<TreeNode*, TreeNode*> mp;
        parents(mp, root, NULL);

        set<TreeNode*> visited;
        queue<TreeNode*> q1;

        q1.push(target);
        visited.insert(target);

        int total = 0;

        while (!q1.empty() && total < k) {

            int size = q1.size();

            for (int i = 0; i < size; i++) {

                TreeNode* node = q1.front();
                q1.pop();

                if (mp[node] != NULL &&
                    visited.find(mp[node]) == visited.end()) {

                    q1.push(mp[node]);
                    visited.insert(mp[node]);
                }

                if (node->left != NULL &&
                    visited.find(node->left) == visited.end()) {

                    q1.push(node->left);
                    visited.insert(node->left);
                }

                if (node->right != NULL &&
                    visited.find(node->right) == visited.end()) {

                    q1.push(node->right);
                    visited.insert(node->right);
                }
            }

            total++;
        }

        vector<int> ans;

        while (!q1.empty()) {
            ans.push_back(q1.front()->val);
            q1.pop();
        }

        return ans;
    }
};