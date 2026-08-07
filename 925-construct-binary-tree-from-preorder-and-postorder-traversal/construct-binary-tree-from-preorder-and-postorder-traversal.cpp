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
    unordered_map<int, int> mp;

    TreeNode* build(vector<int>& pre, int preL, int preR,
                    vector<int>& post, int postL, int postR) {

        if (preL > preR)
            return nullptr;

        TreeNode* root = new TreeNode(pre[preL]);

        if (preL == preR)
            return root;

        int leftRoot = pre[preL + 1];

        int idx = mp[leftRoot];

        int leftSize = idx - postL + 1;

        root->left = build(pre,
                           preL + 1,
                           preL + leftSize,
                           post,
                           postL,
                           idx);

        root->right = build(pre,
                            preL + leftSize + 1,
                            preR,
                            post,
                            idx + 1,
                            postR - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {

        for (int i = 0; i < postorder.size(); i++)
            mp[postorder[i]] = i;

        return build(preorder,
                     0,
                     preorder.size() - 1,
                     postorder,
                     0,
                     postorder.size() - 1);
    }
};