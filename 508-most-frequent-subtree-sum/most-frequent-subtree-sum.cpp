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
    vector<TreeNode*>ans;
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        ans.push_back(root);
        inorder(root->left);
        inorder(root->right);
    }
    void check(TreeNode* root , int &sum){
        if(root == NULL){
            return;
        }
        sum+=root->val;
        check(root->left , sum);
        check(root->right , sum);
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int , int > mp;
        inorder(root);
        for(int i = 0; i<ans.size() ; i++){
            int sum = 0;
            check (ans[i] ,sum);
            mp[sum]++;
        }
        int maxi = 0;
        for(auto i : mp){
            maxi = max(maxi , i.second);
        }
        vector<int>most;
        for(auto i : mp){
            if(i.second == maxi){
                most.push_back(i.first);
            }
        }
        return most;
    }
};