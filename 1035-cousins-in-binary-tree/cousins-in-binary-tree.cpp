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

    void inorder(TreeNode* root,
                 TreeNode*& temp,
                 int x) {

        if (root == NULL) {
            return;
        }

        if (root->val == x) {
            temp = root;
        }

        inorder(root->left, temp, x);
        inorder(root->right, temp, x);
    }

    bool isCousins(TreeNode* root,
                   int x,
                   int y) {

        TreeNode* root1 = NULL;
        TreeNode* root2 = NULL;

        inorder(root, root1, x);
        inorder(root, root2, y);

        map<TreeNode*, int> levelMap;
        map<TreeNode*, TreeNode*> parentMap;

        queue<TreeNode*> q1;
        q1.push(root);

        int level = 0;

        while (!q1.empty()) {

            int size = q1.size();

            for (int i = 0; i < size; i++) {

                TreeNode* node = q1.front();
                q1.pop();

                levelMap[node] = level;

                if (node->left != NULL) {
                    q1.push(node->left);
                    parentMap[node->left] = node;
                }

                if (node->right != NULL) {
                    q1.push(node->right);
                    parentMap[node->right] = node;
                }
            }

            level++;
        }

        if (levelMap[root1] ==
                levelMap[root2] &&
            parentMap[root1] !=
                parentMap[root2]) {

            return true;
        }

        return false;
    }
};