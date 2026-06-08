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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>nums1;
        stack<int>nums2;
        while(l1!=NULL){
            nums1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL){
            nums2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode* head = new ListNode((nums1.top() + nums2.top())%10);
        ListNode* temp = head;
        int carry = (nums1.top() + nums2.top())/10;
        nums1.pop();
        nums2.pop();

        while(!nums1.empty() && !nums2.empty()){
            int x = nums1.top() + nums2.top() + carry;
            nums1.pop();
            nums2.pop();
            carry = x /10;
            int y = x%10;
            ListNode* ptr= new ListNode(y);
            ptr->next = temp;
            temp = ptr;

        }
        while(!nums1.empty()){
            int x = nums1.top() + carry;
            nums1.pop();
            
            carry = x /10;
            int y = x%10;
            ListNode* ptr= new ListNode(y);
            ptr->next = temp;
            temp = ptr;

        }
        while(!nums2.empty()){
            int x = nums2.top() + carry;
            nums2.pop();
            
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
        head = temp;
        return head;

        

    }
};