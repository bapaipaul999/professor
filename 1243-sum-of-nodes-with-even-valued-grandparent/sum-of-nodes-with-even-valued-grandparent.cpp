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

    void check(map<TreeNode*, TreeNode*>& mp,
               TreeNode* root,
               int& ans) {

        if (root == NULL) {
            return;
        }

        TreeNode* parent = mp[root];

        if (parent != NULL &&
            mp[parent] != NULL) {

            int x = mp[parent]->val;

            if (x % 2 == 0) {
                ans += root->val;
            }
        }

        check(mp, root->left, ans);
        check(mp, root->right, ans);
    }

    int sumEvenGrandparent(TreeNode* root) {

        map<TreeNode*, TreeNode*> mp;

        parents(mp, root, NULL);

        int ans = 0;

        check(mp, root, ans);

        return ans;
    }
};