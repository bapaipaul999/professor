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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<int> temp;

        while (head != NULL) {
            temp.push_back(head->val);
            head = head->next;
        }

        int n = temp.size();
        int l = 0;
        int count = 1;

        while (l < n) {
            int r = min(l + count - 1, n - 1);

            // Actual size of this group
            int size = r - l + 1;

            // Reverse only even-sized groups
            if (size % 2 == 0) {
                int left = l;
                int right = r;

                while (left < right) {
                    swap(temp[left], temp[right]);
                    left++;
                    right--;
                }
            }

            l = r + 1;
            count++;
        }

        // Build linked list again
        ListNode* newHead = new ListNode(temp[0]);
        ListNode* ptr = newHead;

        for (int i = 1; i < n; i++) {
            ptr->next = new ListNode(temp[i]);
            ptr = ptr->next;
        }

        return newHead;
    }
};