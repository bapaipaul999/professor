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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        ListNode* ptr = head;

        while (ptr != NULL) {
            nums.push_back(ptr->val);
            ptr = ptr->next;
        }

        int n = nums.size();
        stack<int> s1;

        for (int i = n - 1; i >= 0; i--) {
            int curr = nums[i];  

            while (!s1.empty() && s1.top() <= curr) {
                s1.pop();
            }

            if (s1.empty()) {
                nums[i] = 0;
            } else {
                nums[i] = s1.top();
            }

            s1.push(curr);
        }

        return nums;
    }
};