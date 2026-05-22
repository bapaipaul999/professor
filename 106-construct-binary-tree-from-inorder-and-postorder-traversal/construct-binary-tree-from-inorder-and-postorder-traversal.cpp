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
    int search(vector<int>& inorder, int val, int left, int right) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* helper(vector<int>& postorder, vector<int>& inorder, int& postindex,
                     int left, int right) {
        if (left > right) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postindex]);
        int inindex = search(inorder, postorder[postindex], left, right);
        postindex--;
        root->right = helper(postorder, inorder, postindex, inindex + 1, right);
        root->left = helper(postorder, inorder, postindex, left, inindex - 1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postindex = postorder.size() - 1;
        return helper(postorder, inorder, postindex, 0, inorder.size() - 1);
    }
};