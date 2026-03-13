class Solution {
public:
    long long todays(vector<int>& nums, int mid){
        long long count = 1;
        int sum = 0;
        for(int i = 0 ; i< nums.size();i++){
            if(sum+nums[i]>mid){
                count++;
                sum = 0;
            }
            sum +=nums[i];
        }
        return count;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        int x = *max_element(nums.begin(),nums.end());
        int sum = 0;
        for(int i = 0 ; i< nums.size();i++){
            sum +=nums[i];
        }
        int start = x;
        int end = sum;
        int ans = sum;
        while(start <= end){
            int mid = start + (end - start)/2;
            long long y = todays(nums,mid);
            if(y<=days){
                end = mid -1;
                ans = mid;
            }
            else{
                start = mid +1;
            }
        }
        return ans;
    }
};