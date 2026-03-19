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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>check;
        for(int i = 0 ; i< nums.size(); i++){
            check.insert(nums[i]);
        }
        vector<int>ans;
        ListNode* ptr = head;
        while(ptr!=NULL){
            if(check.find(ptr->val)!=check.end()){
                ptr = ptr->next;
                continue;
            }
            ans.push_back(ptr->val);
            ptr = ptr->next;
        }
        head =  NULL;
        ptr = head;
        for(auto i : ans){
            ListNode* newnode = new ListNode(i);
            if(head == NULL){
                head = newnode;
                ptr = newnode;

            }
            else{
                
                ptr ->next = newnode;
                ptr = newnode;
            }
        }
        return head;
    }
};