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
    ListNode* doubleIt(ListNode* head) {
        stack<int>nums1;
        
        while(head!=NULL){
            nums1.push(head->val);
            head = head->next;
        }
        ListNode* temp = new ListNode((nums1.top()*2)%10);
        int carry = (nums1.top()*2)/10;
        nums1.pop();
        while(!nums1.empty()){
            int x = nums1.top()*2 + carry;
            nums1.pop();
            
            carry = x /10;
            int y = x%10;
            ListNode* ptr= new ListNode(y);
            ptr->next = temp;
            temp = ptr;
        }
        if (carry) {
            ListNode* ptr = new ListNode(carry);
            ptr->next = temp;
            temp = ptr;
        }
        return temp;
    }
};