class Solution {
public:
    int f(int index, vector<int>& nums, vector<int>& dp) {

        // Already reached the last index
        if (index >= nums.size() - 1) {
            return 0;
        }

        // Already calculated
        if (dp[index] != -1) {
            return dp[index];
        }

        int ans = INT_MAX;

        // Try every possible jump
        for (int jump = 1; jump <= nums[index]; jump++) {

            int next = f(index + jump, nums, dp);

            if (next != INT_MAX) {
                ans = min(ans, 1 + next);
            }
        }

        return dp[index] = ans;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);

        return f(0, nums, dp);
    }
};