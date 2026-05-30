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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q1;
        q1.push(root);
        int level = 0;
        while (!q1.empty()) {
            int size = q1.size();
            int x = 0;
            int y = INT_MAX;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q1.front();
                
                q1.pop();
                
                if (node->left != NULL) {
                    q1.push(node->left);
                }
                if (node->right != NULL) {
                    q1.push(node->right);
                }
                if(level%2 == 0){
                    if(node -> val % 2 == 1 && node->val >x){
                        x = node->val;
                        continue;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    if(node -> val % 2 == 0 && node->val < y){
                        y = node->val;
                        continue;
                    }
                    else{
                        return false;
                    }
                }
            }
            level++;
        }
        return true;
    }
};