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
    bool isPalindrome(ListNode* head) {
        stack<int>check;
        ListNode* ptr = head;
        while(ptr != NULL){
            check.push(ptr -> val);
            ptr = ptr -> next;
        }
        ptr = head;
        while(ptr != NULL){
            int x = check.top();
            if(x != ptr->val){
                return false;
            }
            check.pop();
            ptr = ptr -> next;
        }
        return true;

    }
};