class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) {
        long long count = 0;
        int left = 0;
        int right = 0;
        while(right < nums.size()){
            if(right == 0){
                count++;
                right++;
                continue;
            }
            if(nums[right-1] - nums[right] != 1){
                left = right;
            }
            count+= right - left +1;
            right++;
        }
        return count;
    }
};