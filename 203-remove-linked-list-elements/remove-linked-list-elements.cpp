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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return head;
        }
        vector<int>check;
        ListNode* ptr = head;
        while(ptr!=NULL){
            if(ptr->val == val){
                ptr = ptr->next;
                continue;
            }
            check.push_back(ptr->val);
            ptr = ptr->next;
        }
        
        if(check.empty()){
            head = NULL;
            return head;
        }
        head = NULL;
        ptr = head;
        for(auto i : check){
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