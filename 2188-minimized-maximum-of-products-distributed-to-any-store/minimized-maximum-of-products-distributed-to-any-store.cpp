class Solution {
public:
    int find(vector<int> nums , int mid){
        int count = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            count += (nums[i] + mid - 1)/mid;
        }
        return count;
    }
    int minimizedMaximum(int n, vector<int>& nums) {
        int ans = -1;
        int start = 1;
        int end = *max_element(nums.begin() , nums.end());
        int mid = start + (end - start) /2;
        while(start <= end){
            int x = find(nums , mid);
            if(x<= n){
                ans = mid;
                end = mid-1;

            }
            else{
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        return ans;
    }
};