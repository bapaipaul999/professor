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
    int pairSum(ListNode* head) {
        vector<int>ans;
        while(head!=NULL){
            ans.push_back(head->val);
            head = head->next;
        }
        int maxi = 0;
        int left = 0;
        int right = ans.size()-1;
        while(left<right){
            maxi = max(maxi , ans[left]+ans[right]);
            left++;
            right--;
        }
        return maxi;
    }
};