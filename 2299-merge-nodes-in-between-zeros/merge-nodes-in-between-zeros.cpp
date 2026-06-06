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
    ListNode* mergeNodes(ListNode* head) {

        vector<int> ref;
        int sum = 0;

        head = head->next;   // skip first 0

        while(head != NULL){

            if(head->val == 0){
                ref.push_back(sum);
                sum = 0;
            }
            else{
                sum += head->val;
            }

            head = head->next;
        }

        ListNode* temp = new ListNode(ref[0]);
        ListNode* ptr = temp;

        for(int i = 1; i < ref.size(); i++){
            ptr->next = new ListNode(ref[i]);
            ptr = ptr->next;
        }

        return temp;
    }
};