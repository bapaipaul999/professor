class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int left = 0;
        int right = 0;
        int count = 0;
        int len = 0;
        int sum = 0;
        while(right < nums.size()){
            if(len<k){
                sum = sum + nums[right];
                right++;
                len++;
                continue;
            }
            int avg = sum /len;
            if(avg>=threshold){
                count++;
            }
            sum = sum + nums[right] - nums[left];
            right++;
            left++;

        }
        int avg = sum /len;
            if(avg>=threshold){
                count++;
            }
        return count;
    }
};