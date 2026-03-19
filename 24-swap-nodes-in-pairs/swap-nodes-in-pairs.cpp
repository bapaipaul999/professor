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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* ptr = head;
        ListNode* newhead = head->next;
        ListNode* prev = NULL;

        while (ptr != NULL && ptr->next != NULL) {
            ListNode* ptr2 = ptr->next;
            ptr->next = ptr2->next;
            ptr2->next = ptr;
            if (prev != NULL) {
                prev->next = ptr2;
            }

            prev = ptr;
            ptr = ptr->next;
        }

        return newhead;
    }
};