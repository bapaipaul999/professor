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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>>q1;
        int maxsize = 0;
        q1.push({root,0});
        while(!q1.empty()){
            int size = q1.size();
            unsigned long long leftpos = q1.front().second;
            unsigned long long rightpos = q1.back().second;

            maxsize = max(maxsize,(int)(rightpos-leftpos)+1);

            for(int i = 0 ; i<size ; i++ ) {

                auto node = q1.front();

                q1.pop();

                if(node.first->left!=NULL){
                    q1.push({node.first->left , node.second*2+1});
                    
                }
                if(node.first->right!=NULL){
                    q1.push({node.first->right , node.second*2+2});
                    
                }

            }
        }
        return maxsize;
    }
};