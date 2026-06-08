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
    void insertionSort(vector<int>& nums) {
        int n = nums.size();
        
        
        for (int i = 1; i < n; i++) {
            int key = nums[i]; 
            int j = i - 1; 
            
            
            while (j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j];
                j--;
            }
            
            nums[j + 1] = key; 
        }
        
        
    }
    ListNode* insertionSortList(ListNode* head) {
        vector<int>ans;
        while(head!=NULL){
            ans.push_back(head->val);
            head = head->next;
        }
        insertionSort(ans);
        ListNode* newHead = new ListNode(ans[0]);
        ListNode* temp = newHead;

        for(int i = 1 ; i<ans.size() ; i++){
            temp->next = new ListNode(ans[i]);
            temp = temp->next;
        }
        return newHead;
    }
};