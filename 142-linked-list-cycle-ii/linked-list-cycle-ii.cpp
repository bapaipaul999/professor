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
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;
        set<ListNode*>check;
      
        while(temp!=NULL){
            if(check.find(temp)!=check.end()){
                return temp;
            }
            check.insert(temp);
            temp = temp -> next;
        }
        return NULL;
    }
};