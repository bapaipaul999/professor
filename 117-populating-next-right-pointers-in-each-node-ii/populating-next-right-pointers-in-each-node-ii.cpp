/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
         Node* temp = root;
        if(root == NULL){
            return root;
        }
        queue<Node*>q1;
        vector<vector<Node*>>ans;
        q1.push(temp);
        while(!q1.empty()){
            int size = q1.size();
            
            vector<Node*>level;
            for(int i = 0 ; i<size ; i++){
                Node* ptr = q1.front();
                q1.pop();
                level.push_back(ptr);
                if(ptr->left!=NULL){
                    q1.push(ptr->left);
                }
                if(ptr->right!=NULL){
                    q1.push(ptr->right);
                }
            }
            ans.push_back(level);
        }
        for(int i = 0 ; i<ans.size() ; i++){
            int size = ans[i].size();
            Node* ptr = ans[i][0];
            for(int j = 1 ; j<size ; j++){
                ptr->next = ans[i][j];
                ptr = ptr->next;
            }
            ans[i][size-1]->next = NULL;
        }
        return root;
    }
};