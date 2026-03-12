class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int mid = start + (end -start)/2;
        
        while(start < end){
            if(nums[start] < nums[end])
                return nums[start];
            if(nums[mid] >= nums[0]){
                start = mid +1;
            }

            else if(nums[mid] < nums[0]){
                end = mid;
            }
            mid = start + (end -start)/2;
        }
        return nums[start];
    }
};