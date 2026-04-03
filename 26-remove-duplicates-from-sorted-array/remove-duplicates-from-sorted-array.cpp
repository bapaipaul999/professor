class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>check;
        int j = 0;
        for(int i = 0; i< nums.size();i++){
            if(check.find(nums[i])!=check.end()){
                continue;
            }
            check[nums[i]]++;
            nums[j] = nums[i];
            j++;
        }
        return j;
    }
};