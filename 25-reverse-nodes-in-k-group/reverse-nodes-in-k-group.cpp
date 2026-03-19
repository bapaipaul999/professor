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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr = head;
        if(head == NULL|| head->next == NULL){
            return head;
        }
        int count = 0;
        vector<int>ans;
        while(ptr!=NULL){
            count++;
            ans.push_back(ptr->val);
            ptr = ptr->next;
        }
        int x = count/k;
        int count1 = 0;
        for(int i = 0 ; i< x ; i++){
            reverse(ans.begin() + count1, ans.begin() + count1 + k);
            count1 = count1 +k ;
        }
        ptr = head;
        for(auto i:ans){
            ptr->val = i;
            ptr = ptr->next;
        }
        return head;
    }
};