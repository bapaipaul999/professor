class Solution {
public:
    int f(int n, int target, vector<vector<int>>& dp, vector<int>& nums) {

        if(target == 0) {
            return 0;
        }

        if(n < 0) {
            return -1;
        }

        if(dp[n][target] != -2) {
            return dp[n][target];
        }

        // Don't take
        int notTake = f(n - 1, target, dp, nums);

        // Take
        int take = -1;

        if(nums[n] <= target) {
            int x = f(n - 1, target - nums[n], dp, nums);

            if(x != -1) {
                take = 1 + x;
            }
        }

        return dp[n][target] = max(take, notTake);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {

        int n = nums.size();

        vector<vector<int>> dp(
            n,
            vector<int>(target + 1, -2)
        );

        return f(n - 1, target, dp, nums);
    }
};