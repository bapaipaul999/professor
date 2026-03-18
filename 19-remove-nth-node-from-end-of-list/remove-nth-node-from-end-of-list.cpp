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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;

        int count = 0;
        ListNode* ptr = head;

        // count nodes
        while(ptr != NULL){
            count++;
            ptr = ptr->next;
        }

        // delete head case
        if(n == count){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int x = count - n;  

        ptr = head; 

        for(int i = 1; i < x; i++){
            ptr = ptr->next;
        }

        ListNode* ptr2 = ptr->next;
        ptr->next = ptr2->next;
        delete ptr2;

        return head;
    }
};