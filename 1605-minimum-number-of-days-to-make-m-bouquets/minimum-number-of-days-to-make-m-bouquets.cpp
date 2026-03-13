class Solution {
public:
    long long bouquets(vector<int>& nums, int mid, int k){
        int count = 0;
        long long total = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= mid){
                count++;
                if(count == k){
                    total++;
                    count = 0;
                }
            }
            else{
                count = 0;
            }
        }

        return total;
    }

    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();

        if((long long)m * k > n)
            return -1;

        int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        int ans = -1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            long long made = bouquets(nums, mid, k);

            if(made >= m){
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