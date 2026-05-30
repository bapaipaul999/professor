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
    vector<TreeNode*> ans;

    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        ans.push_back(root);

        inorder(root->left);
        inorder(root->right);
    }

    void check1(TreeNode* root, int& sum) {

        TreeNode* temp1 = root;
        TreeNode* temp2 = root;

        int sum1 = 0;
        int sum2 = 0;

        // start left
        bool goLeft = true;

        while (temp1 != NULL) {

            if (goLeft) {

                if (temp1->left == NULL) {
                    break;
                }

                temp1 = temp1->left;
            }
            else {

                if (temp1->right == NULL) {
                    break;
                }

                temp1 = temp1->right;
            }

            sum1++;
            goLeft = !goLeft;
        }

        // start right
        goLeft = false;

        while (temp2 != NULL) {

            if (goLeft) {

                if (temp2->left == NULL) {
                    break;
                }

                temp2 = temp2->left;
            }
            else {

                if (temp2->right == NULL) {
                    break;
                }

                temp2 = temp2->right;
            }

            sum2++;
            goLeft = !goLeft;
        }

        sum = max(sum1, sum2);
    }

    int longestZigZag(TreeNode* root) {

        inorder(root);

        int total = 0;

        for (int i = 0; i < ans.size(); i++) {

            int sum = 0;

            check1(ans[i], sum);

            total = max(total, sum);
        }

        return total;
    }
};