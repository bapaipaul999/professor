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
class CBTInserter {
public:
    TreeNode* root;
    queue<TreeNode*> q;

    CBTInserter(TreeNode* root) {
        this->root = root;

        queue<TreeNode*> temp;
        temp.push(root);

        while (!temp.empty()) {

            TreeNode* node = temp.front();
            temp.pop();

            if (node->left != NULL) {
                temp.push(node->left);
            }

            if (node->right != NULL) {
                temp.push(node->right);
            }

            if (node->left == NULL ||
                node->right == NULL) {
                q.push(node);
            }
        }
    }

    int insert(int val) {

        TreeNode* parent = q.front();
        TreeNode* newNode = new TreeNode(val);

        if (parent->left == NULL) {
            parent->left = newNode;
        }
        else {

            parent->right = newNode;
            q.pop();
        }

        q.push(newNode);

        return parent->val;
    }

    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */