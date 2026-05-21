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
    map<int,map<int,multiset<int>>>mp;
    void solve(TreeNode* root, int col , int level){
        if(root == NULL){
            return;
        }
        mp[col][level].insert(root->val);
        solve(root->left,col-1,level+1);
        solve(root->right,col+1,level+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root,0,0);
        vector<vector<int>>ans;
        for(auto i : mp){
            vector<int>temp;
            for(auto j : i.second){
                for(auto val : j.second){
                    temp.push_back(val);

                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};