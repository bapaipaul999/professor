class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.rbegin() , nums.rend());
        long long ans = 0;
        for(int i = 0 ; i<k ; i++){
            if(mul>1){
                ans = ans + 1LL*mul*nums[i];
                mul--;
            }
            else{
                ans = ans + nums[i];
            }
        }
        return ans;
    }
};