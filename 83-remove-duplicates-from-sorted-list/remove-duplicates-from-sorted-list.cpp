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
        set<int>check;
        ListNode* ptr = head;
        while(ptr != NULL){
            check.insert(ptr->val);
            ptr = ptr->next;
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
                ptr -> next = newnode;
                ptr = newnode;
            }
        }
        return head;

    }
};