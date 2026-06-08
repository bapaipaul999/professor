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
    void reorderList(ListNode* head) {
        vector<ListNode*>nums;
        ListNode* temp = head ;
        while(temp!=NULL){
            nums.push_back(temp);
            ListNode*prev = temp;
            temp = temp->next;
            prev ->next = NULL;
        }
        int left = 0;
        int right = nums.size()-1;
        vector<ListNode*>nums1;
        while(left<=right){
            if(left == right){
                nums1.push_back(nums[left]);
                break;
            }
            nums1.push_back(nums[left]);
            nums1.push_back(nums[right]);
            left++;
            right--;
        }
        ListNode* newHead = nums1[0];
        ListNode* ptr = newHead;
        for(int i = 1 ; i< nums1.size() ; i++){
            ptr -> next = nums1[i];
            ptr = ptr->next;
        }
        
    }
};