/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    vector<TreeNode*> check;

    void find(TreeNode* root, int val) {

        if (root == NULL) {
            return;
        }

        if (root->val == val) {
            check.push_back(root);
        }

        find(root->left, val);
        find(root->right, val);
    }

    bool same(TreeNode* root,
              ListNode* head) {

        if (head == NULL) {
            return true;
        }

        if (root == NULL) {
            return false;
        }

        if (root->val != head->val) {
            return false;
        }

        if (head->next == NULL) {
            return true;
        }

        return same(root->left,
                    head->next) ||
               same(root->right,
                    head->next);
    }

    bool isSubPath(ListNode* head,
                   TreeNode* root) {

        find(root, head->val);

        for (int i = 0;
             i < check.size();
             i++) {

            if (same(check[i], head)) {
                return true;
            }
        }

        return false;
    }
};