class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_count = 0;
        int count = 0;
        int left = 0;
        int right = 0;
        while(right<nums.size()){
            if(nums[right]==0){
                count++;
            }
            while(count > k){
                if(nums[left]==1){
                    left++;
                }
                else{
                    count--;
                    left++;
                }
            }
            max_count = max(max_count , right - left+1);
            right++;
        }
        return max_count;
    }
};