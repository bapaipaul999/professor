class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int right = 0;
        int max_sum = 0;
        map<int,int>check;
        while(right<nums.size()){
            while(check[nums[right]]==1){
                check[nums[left]]--;
                sum = sum - nums[left];
                left++;
            }
            check[nums[right]]++;
            sum = sum+nums[right];
            max_sum = max(max_sum,sum);
            right++;
        }
        return max_sum;
    }
};