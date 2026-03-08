class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int>check;
        int j = 0;
        for(int i = 0 ; i< nums.size() ; i++){
            if(check.count(nums[i])){
                continue;
            }
            check.insert(nums[i]);
            nums[j] = nums[i];
            j++;
        }
        return j;
    }
};