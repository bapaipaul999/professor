class Solution {
public:
    bool f(int index, vector<int>& nums, vector<int>& dp) {
        // Reached last index
        if (index >= nums.size() - 1) {
            return true;
        }

        // Already calculated
        if (dp[index] != -1) {
            return dp[index];
        }

        // Try every possible jump
        for (int jump = 1; jump <= nums[index]; jump++) {

            if (f(index + jump, nums, dp)) {
                return dp[index] = 1;
            }
        }

        return dp[index] = 0;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        return f(0, nums, dp);
    }
};