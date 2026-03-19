/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int>check;
        
        ListNode* ptr = head;
        while(ptr!=NULL){
            check[ptr->val]++;
            ptr = ptr -> next;

        }
        ptr = head;
        vector<int>ans;
        while(ptr!=NULL){
            if(check[ptr->val] == 1){
                ans.push_back(ptr->val);
            }
            ptr = ptr -> next;

        }
        head = NULL;
        ptr = head;
        for(auto i : ans){
            ListNode* newnode = new ListNode(i);
            if(head == NULL){
                head = newnode;
                ptr = newnode;
            }
            else{
                ptr ->next = newnode;
                ptr = newnode;
            }
        }
        return head;

    }
};