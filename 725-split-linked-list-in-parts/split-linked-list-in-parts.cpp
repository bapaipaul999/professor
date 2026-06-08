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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp1 = head;
        while (temp1 != NULL) {
            n++;
            temp1= temp1->next;
        }
        
        int x = n / k;
        int y = n % k;
        vector<int>nums2;
        for (int i = 0; i < k ; i++) {

            if (y > 0) {
                nums2.push_back(x + 1);
                y--;
                continue;
            }
            nums2.push_back(x);
        }
        vector<ListNode*>ans;
        ListNode* temp = head;
        
        for(int i = 0 ; i<k ; i++){
            int size = nums2[i];
            int count = 1;
            ListNode*prev = temp;
            if(size ==0){
                ans.push_back(NULL);
                continue;
            }
            while(count<size){
                temp = temp ->next;
                count++;
            }
            ListNode*ptr = temp->next;
            temp->next = NULL;
            temp = ptr;
            ans.push_back(prev);
        }
        return ans;
    }
};