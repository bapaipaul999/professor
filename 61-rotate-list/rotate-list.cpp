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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (head == NULL || head->next == NULL) return head;

        int count = 1;
        ListNode* ptr = head;

     
        while (ptr->next != NULL) {
            ptr = ptr->next;
            count++;
        }

        k = k % count;   
        if (k == 0) return head;

        int steps = count - k; 

        ListNode* ptr2 = head;
        for (int i = 1; i < steps; i++) {
            ptr2 = ptr2->next;
        }

   
        ptr->next = head;

  
        head = ptr2->next;
        ptr2->next = NULL;

        return head;
    }
};