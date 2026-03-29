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
    ListNode* removeNodes(ListNode* head) {
        ListNode* ptr = head;
        vector<int> ans;

        while (ptr != NULL) {
            ans.push_back(ptr->val);
            ptr = ptr->next;
        }

        int n = ans.size();
        vector<int> temp(n);
        stack<int> s1;

        for (int i = n - 1; i >= 0; i--) {
            while (!s1.empty() && s1.top() <= ans[i]) {
                s1.pop();
            }

            if (s1.empty()) {
                temp[i] = -1;
            } else {
                temp[i] = s1.top();
            }

            s1.push(ans[i]);
        }

        ListNode* newHead = NULL;
        ListNode* ptr2 = NULL;

        for (int i = 0; i < n; i++) {
            if (temp[i] == -1) {
                ListNode* node = new ListNode(ans[i]);

                if (newHead == NULL) {
                    newHead = node;
                    ptr2 = node;
                } else {
                    ptr2->next = node;
                    ptr2 = ptr2->next;
                }
            }
        }

        return newHead;
    }
};