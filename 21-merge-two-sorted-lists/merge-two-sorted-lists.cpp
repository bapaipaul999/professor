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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int>ans;
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        while(ptr1!=NULL){
            ans.push_back(ptr1 -> val);
            ptr1 = ptr1 -> next;
        }
        while(ptr2!=NULL){
            ans.push_back(ptr2 -> val);
            ptr2 = ptr2 -> next;
        }
        sort(ans.begin(),ans.end());
        ListNode* head = NULL;
        ListNode* ptr3 = head;
        for(auto i : ans ){
            if(head == NULL){
                ListNode* newNode = new ListNode(i);
                head = newNode;
                ptr3 = newNode;
            }
            else{
                ListNode* newNode = new ListNode(i);
                ptr3 -> next =newNode;
                ptr3 = newNode;
            }
        }
        return head;
    }
};