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
    ListNode* mergeInBetween(ListNode* List1, int a, int b, ListNode* List2) {
        int count1 = 1;
        int count2 = 1;
        ListNode* temp1 = List1;
        ListNode* temp2 = List1;
        ListNode* temp3 = List2;
        while(count1<a){
            temp1 = temp1->next;
            count1++;
        }
        while(count2<=b+1){
            temp2 = temp2->next;
            count2++;
        }
        while(temp3->next!=NULL){
            temp3 = temp3->next;
        }
        temp1->next = List2;
        temp3->next = temp2;
        return List1;

    }
};