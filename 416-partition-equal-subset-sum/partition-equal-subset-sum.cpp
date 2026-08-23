class Solution {
public:
    bool f(int n, int target, vector<vector<int>>& dp, vector<int>& nums) {
        if(target == 0) {
            return true;
        }

        if(n == 0) {
            return nums[0] == target;
        }

        if(dp[n][target] != -1) {
            return dp[n][target];
        }

        bool notTake = f(n - 1, target, dp, nums);

        bool take = false;

        if(nums[n] <= target) {
            take = f(n - 1, target - nums[n], dp, nums);
        }

        return dp[n][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        if(sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(n - 1, target, dp, nums);
    }
};