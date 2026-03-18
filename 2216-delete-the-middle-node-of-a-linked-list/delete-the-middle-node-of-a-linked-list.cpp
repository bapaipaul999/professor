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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            head = NULL;
            return head;
        }
        

        int count = 0;
        ListNode* ptr = head;

       
        while(ptr != NULL){
            count++;
            ptr = ptr->next;
        }
        ptr = head;
        int i = 1;
        while(i<count/2 && ptr -> next != NULL){
            ptr  = ptr -> next ;
            i++;

        }
        ListNode* ptr2 = ptr -> next;
        ptr -> next = ptr2->next;
        delete ptr2;
        return head;

    }
};