class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        deque<int>dq;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] == pivot){
                dq.push_back(nums[i]);
            }
        }
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i]>pivot){
                dq.push_front(nums[i]);
            }
        }
        for(int i = nums.size()-1 ; i>=0 ; i--){
            if(nums[i] < pivot){
                dq.push_back(nums[i]);
            }
        }
        vector<int>ans;
        while(!dq.empty()){
            ans.push_back(dq.back());
            dq.pop_back();
        }
        return ans;
    }
};