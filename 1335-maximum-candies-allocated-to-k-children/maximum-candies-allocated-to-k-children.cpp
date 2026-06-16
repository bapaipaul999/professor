class Solution {
public:
    long long find(vector<int>nums , int mid){
        long long ans = 0;
        for(int i = 0; i<nums.size() ; i++){
            ans += nums[i]/mid;
        }
        return ans ;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int start = 1;
        int end = *max_element(candies.begin() , candies.end());
        int mid = start + (end - start)/2;
        int ans = 0;
        while(start <= end ){
            mid = start + (end - start)/2;
            long long x = find(candies , mid);
            if(x >= k){
                start = mid + 1;
                ans = mid;
            }
            else{
                end = mid-1;
            }

        }
        return ans;
    }
};