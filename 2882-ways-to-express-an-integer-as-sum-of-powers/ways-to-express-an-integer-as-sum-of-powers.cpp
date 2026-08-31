class Solution {
public:
    const int MOD = 1e9 + 7;

    long long power(int a, int x, int limit) {
        long long res = 1;

        for (int j = 0; j < x; j++) {
            res *= a;

            if (res > limit)
                return res;
        }

        return res;
    }

    int f(int i, int target, vector<vector<int>>& dp, int x) {
        if (target == 0)
            return 1;

        if (i == 0 || target < 0)
            return 0;

        if (dp[i][target] != -1)
            return dp[i][target];

        int notTake = f(i - 1, target, dp, x);

        int take = 0;

        long long p = power(i, x, target);

        if (p <= target) {
            take = f(i - 1, target - p, dp, x);
        }

        return dp[i][target] = (take + notTake) % MOD;
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return f(n, n, dp, x);
    }
};