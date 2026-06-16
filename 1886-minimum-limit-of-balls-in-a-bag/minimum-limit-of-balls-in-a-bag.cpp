class Solution {
public:
    long long find(vector<int>& nums , int mid){
        long long count =0;
        for(int i = 0 ; i<nums.size() ; i++){
            count += (nums[i] + mid - 1)/mid;
        }
        return count;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        int ans = -1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            long long x = find(nums, mid);

            if(x <= maxOperations+n){
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