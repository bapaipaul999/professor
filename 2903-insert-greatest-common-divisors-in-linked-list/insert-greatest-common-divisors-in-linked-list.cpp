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
    int gcd(int a, int b) {
        while (b) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        ListNode* curr = head;

        while (curr != NULL && curr->next != NULL) {

            int g = gcd(curr->val, curr->next->val);

            ListNode* newNode = new ListNode(g);

            newNode->next = curr->next;
            curr->next = newNode;

            curr = newNode->next;
        }

        return head;
    }
};