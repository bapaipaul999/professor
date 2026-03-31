class Solution {
public:
    int funtion(vector<int>&nums , int k){
        if(k<0){
            return 0;
        }
        int left = 0;
        int right = 0;
        int count = 0;
        int special = 0;
        map<int,int>check;
        while(right < nums.size()){
            check[nums[right]]++;
            if(check[nums[right]]==1){
                special++;
            }
            while(special>k){
                if(check[nums[left]]==1){
                    special--;
                }
                check[nums[left]]--;
                left++;
            }
            count = count + right - left +1;
            right ++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return funtion(nums,k) - funtion(nums,k-1);
    }
};