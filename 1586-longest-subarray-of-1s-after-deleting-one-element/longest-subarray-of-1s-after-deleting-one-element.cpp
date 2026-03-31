class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int count = 0;
        int size = 0;
        int k = 1;
        while(right < nums.size()){
            if(count<k){
                if(nums[right] == 0){
                    count++;
                }
                size = max(size,right - left );
                right++;
                continue;
            }
            if(nums[right] == 0){
                count++;
            }
            while(count>k){
                if(nums[left] == 0){
                    count--;
                }
                left++;
            }
            size = max(size,right-left);
            right++;
        }
        return size;
    }
};