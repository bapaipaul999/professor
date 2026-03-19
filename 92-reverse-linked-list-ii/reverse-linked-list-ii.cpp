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
    ListNode* reverseBetween(ListNode* head ,int left, int right) {
        if(head==NULL || head->next == NULL){
            return head;
        }
        ListNode* ptr = head;
        int count = 1;
        stack<int>ans;
        while(ptr!=NULL){
            if(count>=left && count <= right){
                ans.push(ptr->val);
            }
            ptr = ptr->next;
            count++;
        }
        ptr= head;
        count = 1;
        while(ptr!=NULL){
            if(count>=left && count <= right){
                
                ptr -> val = ans.top();
                ans.pop();
            }
            ptr = ptr->next;
            count++;
        }
        return head;

    }
};