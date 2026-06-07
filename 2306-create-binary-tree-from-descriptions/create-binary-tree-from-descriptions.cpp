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
    TreeNode* createBinaryTree(vector<vector<int>>& nums) {
        map<int ,TreeNode*>mp; 
        for(int i = 0; i<nums.size() ; i++){
            TreeNode* x = NULL;
            TreeNode* y = NULL;
            
            if(mp.find(nums[i][0])==mp.end()){
                x = new TreeNode(nums[i][0]);
                mp[nums[i][0]]=x;
            }
            else{
                x= mp[nums[i][0]];
            }
            if(mp.find(nums[i][1])==mp.end()){
                y = new TreeNode(nums[i][1]);
                mp[nums[i][1]]=y;
            }
            else{
                y = mp[nums[i][1]];
            }
            if(nums[i][2] == 1){
                x ->left = y;
            }
            else{
                x->right = y;
            }

        }
        for(int i = 0 ; i<nums.size() ; i++){
            if(mp.find(nums[i][1])!=mp.end()){
                mp.erase(nums[i][1]);
            }
        }
        TreeNode* root = NULL;
        for(auto it : mp){
            root = it.second;
        }
        return root;
    }
};