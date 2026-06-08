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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL){
            return head;
        }
        vector<int>ans;
        ListNode* temp = head;
        while(temp !=NULL){
            ans.push_back(temp->val);
            temp = temp->next;
        }
        deque<int>dq;
        for(int i = 0 ; i<ans.size() ; i++){
            if(ans[i]>=x){
                dq.push_front(ans[i]);
            }
        }
        for(int i = ans.size() -1 ; i>=0 ; i--){
            if(ans[i]<x){
                dq.push_back(ans[i]);
            }
        }
        ListNode* newHead = new ListNode(dq.back());
        ListNode* ptr = newHead;
        dq.pop_back();
        while(!dq.empty()){
            ListNode* temp = new ListNode(dq.back());
            dq.pop_back();
            ptr->next = temp;
            ptr = ptr->next;
        }
        return newHead;

    }
};