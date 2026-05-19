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
   
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int>ans;
       if(root == NULL){
        return ans;
       }
       stack<TreeNode*>s1;
       TreeNode* current = root;
       TreeNode* lastElement = NULL;
       while(current != NULL ||!s1.empty()){
            if(current!=NULL){
                s1.push(current);
                current = current -> left;
            }
            else{
                TreeNode* temp = s1.top() -> right;
                if(temp == NULL || temp == lastElement){
                    temp = s1.top();
                    s1.pop();
                    ans.push_back(temp -> val);
                    lastElement = temp;

                }
                else{
                    current = temp;
                }
            }
       }
        
        return ans;
    }
};