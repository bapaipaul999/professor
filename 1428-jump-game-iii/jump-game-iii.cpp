class Solution {
public:
    bool f(int start, vector<int>& dp, vector<int>& nums) {

        if (start < 0 || start >= nums.size()) {
            return false;
        }

        if (nums[start] == 0) {
            return true;
        }

        if (dp[start] != -1) {
            return dp[start];
        }

        // Mark as visited
        dp[start] = 0;

        bool left = f(start + nums[start], dp, nums);
        bool right = f(start - nums[start], dp, nums);

        return dp[start] = left || right;
    }

    bool canReach(vector<int>& arr, int start) {
        vector<int> dp(arr.size(), -1);

        return f(start, dp, arr);
    }
};