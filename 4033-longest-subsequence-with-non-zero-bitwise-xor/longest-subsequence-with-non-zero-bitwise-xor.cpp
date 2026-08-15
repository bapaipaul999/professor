class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(n, 0);
        if(nums == temp ){
            return 0;
        }
        int ans = 0;
        for(auto it : nums){
            ans = ans ^ it;
        }
        return ans ?n:n-1;
    }
};