class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;
        int start = 0;
        int end = nums.size()-1;
        int mid = start + (end - start )/2;
        while(start <= end){
            if(nums[mid] == target){
                first = mid;
                end = mid -1;

            }
            else if(nums[mid] > target){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
            mid = start + (end - start )/2;
        }
        start = 0;
        end = nums.size()-1;
        mid = start + (end - start )/2;
        while(start <= end){
            if(nums[mid] == target){
                last = mid;
                start = mid+1;

            }
            else if(nums[mid] > target){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
            mid = start + (end - start )/2;
        }
        return {first ,last };
    }
};