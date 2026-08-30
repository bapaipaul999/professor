class Solution {
public:

    int f(int i, int target,
          vector<vector<int>>& dp,
          vector<int>& stones) {

        // We can make sum 0
        if (target == 0) {
            return 0;
        }

        // No stones left
        if (i == 0) {
            return 0;
        }

        if (dp[i][target] != -1) {
            return dp[i][target];
        }

        // Don't take current stone
        int notTake = f(i - 1, target, dp, stones);

        // Take current stone
        int take = 0;

        if (stones[i - 1] <= target) {
            take = stones[i - 1] +
                   f(i - 1,
                     target - stones[i - 1],
                     dp,
                     stones);
        }

        return dp[i][target] =
            max(take, notTake);
    }

    int lastStoneWeightII(vector<int>& stones) {

        int n = stones.size();

        int sum = 0;

        for (int x : stones) {
            sum += x;
        }

        int target = sum / 2;

        vector<vector<int>> dp(
            n + 1,
            vector<int>(target + 1, -1)
        );

        int x = f(n, target, dp, stones);

        return sum - 2 * x;
    }
};