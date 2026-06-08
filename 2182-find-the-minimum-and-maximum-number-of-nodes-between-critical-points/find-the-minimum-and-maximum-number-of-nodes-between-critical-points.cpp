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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> nums;

        while(head){
            nums.push_back(head->val);
            head = head->next;
        }

        vector<int> critical;

        int n = nums.size();

        for(int i = 1; i < n - 1; i++){
            if((nums[i] > nums[i-1] && nums[i] > nums[i+1]) ||
               (nums[i] < nums[i-1] && nums[i] < nums[i+1])){
                critical.push_back(i);
            }
        }

        if(critical.size() < 2){
            return {-1, -1};
        }

        int mn = INT_MAX;

        for(int i = 1; i < critical.size(); i++){
            mn = min(mn, critical[i] - critical[i-1]);
        }

        int mx = critical.back() - critical.front();

        return {mn, mx};
    }
};