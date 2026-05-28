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
    vector<int>ans;
    void inorder(TreeNode* root){
        if(root == NULL){
            return ;
        }
        inorder(root -> left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        inorder(root);
        vector<vector<int>>ans2;

        for(int i = 0 ; i<queries.size() ; i++){
            int mini = -1;
            int maxi = -1;
            int left = 0;
            int right = ans.size()-1;
            int mid = left + (right - left)/2;
            while(left<=right){
                if(ans[mid]>=queries[i]){
                    right = mid-1;
                    maxi = ans[mid];
                }
                else{
                    left = mid+1;
                }
                mid = left + (right - left)/2;
            }
            left = 0;
            right = ans.size() - 1;
            mid = left + (right - left)/2;
            while(left<=right){
                if(ans[mid]<=queries[i]){
                    left = mid+1;
                    mini = ans[mid];
                }
                else{
                    right = mid-1;
                }
                mid = left + (right - left)/2;
            }
            ans2.push_back({mini,maxi});
        }
        return ans2;
    }
};