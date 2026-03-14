class Solution {
public:
    int totals(vector<int>& nums, int mid){
        int count = 1;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];

            if(sum > mid){
                count++;
                sum = nums[i];
            }
        }

        return count;
    }

    int splitArray(vector<int>& nums, int k) {

        int start = *max_element(nums.begin(), nums.end());
        int end = accumulate(nums.begin(), nums.end(), 0);
        int ans = end;

        while(start <= end){

            int mid = start + (end - start) / 2;

            int y = totals(nums, mid);

            if(y <= k){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        return ans;
    }
};