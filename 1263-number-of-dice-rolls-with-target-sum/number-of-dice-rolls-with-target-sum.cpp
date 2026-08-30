class Solution {
public:
    int MOD = 1e9 + 7;

    int f(int n, int target, vector<vector<int>>& dp, int k) {

        // Target reached
        if (target == 0) {
            return (n == 0);
        }

        // No dice left but target still remains
        if (n == 0) {
            return 0;
        }

        // Impossible target
        if (target < 0) {
            return 0;
        }

        if (dp[n][target] != -1) {
            return dp[n][target];
        }

        dp[n][target] = 0;

        // Choose the value of current dice
        for (int i = 1; i <= k; i++) {

            if (i <= target) {

                dp[n][target] =
                    (dp[n][target] +
                     f(n - 1, target - i, dp, k))
                    % MOD;
            }
        }

        return dp[n][target];
    }

    int numRollsToTarget(int n, int k, int target) {

        vector<vector<int>> dp(
            n + 1,
            vector<int>(target + 1, -1)
        );

        return f(n, target, dp, k);
    }
};