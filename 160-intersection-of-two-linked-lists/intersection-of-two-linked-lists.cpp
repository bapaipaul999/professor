/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*>ans;
        ListNode* ptr = headA;
        while(ptr!=NULL){
            ans.insert(ptr);
            ptr = ptr -> next;
        }
        
        ListNode* ptr2 = headB;
        while(ptr2!=NULL){
            if(ans.find(ptr2)!=ans.end()){
                return ptr2;
            }
            ptr2 = ptr2 -> next;
        }
        return NULL;
    }
};