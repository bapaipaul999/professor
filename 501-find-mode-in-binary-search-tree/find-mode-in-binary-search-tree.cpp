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
    void inorder(TreeNode* root , map<int,int>&mp){
        if(root == NULL){
            return;
        }
        inorder(root->left , mp);
        mp[root->val]++;
        inorder(root->right , mp);
    }
    vector<int> findMode(TreeNode* root) {
        map<int,int>mp;
        vector<int>ans;
        inorder(root , mp);
        int x = 0;
        for(auto i : mp){
            x = max(x,i.second);
        }
        for(auto i : mp){
            if(i.second == x){
                ans.push_back(i.first);
            }
        }
        return ans;

    }
};