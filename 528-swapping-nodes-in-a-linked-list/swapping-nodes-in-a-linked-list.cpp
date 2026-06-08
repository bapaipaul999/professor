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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int>ans;
        ListNode* temp = head;
        while(temp!=NULL){
            ans.push_back(temp->val);
            temp = temp->next;
        }
        int n = ans.size();
        swap(ans[k-1] , ans[n-k]);
        ListNode* newHead = new ListNode(ans[0]);
        temp = newHead;
        for(int i = 1 ; i<n ; i++){
            ListNode* ptr = new ListNode(ans[i]);
            temp -> next = ptr;
            temp = temp->next;
        }
        return newHead;
    }
};