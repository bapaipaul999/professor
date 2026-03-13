class Solution {
public:
    long long totalHours(vector<int>& nums, int k){
        long long totalH = 0;

        for(int bananas : nums){
            totalH += (bananas + k - 1) / k;   // ceil division
        }

        return totalH;
    }

    int minEatingSpeed(vector<int>& nums, int h) {
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        int ans = end;

        while(start <= end){
            int mid = start + (end - start) / 2;

            long long hours = totalHours(nums, mid);

            if(hours <= h){
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