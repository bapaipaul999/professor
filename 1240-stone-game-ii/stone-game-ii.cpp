class Solution {
public:
    int f(int i, int m,
          vector<vector<int>>& dp,
          vector<int>& piles,
          vector<int>& suffix) {

        int n = piles.size();

        // Can take all remaining piles
        if (i >= n) {
            return 0;
        }

        if (2 * m >= n - i) {
            return suffix[i];
        }

        if (dp[i][m] != -1) {
            return dp[i][m];
        }

        int ans = 0;
        int taken = 0;

        // X = 1 ... 2*m
        for (int x = 1; x <= 2 * m; x++) {

            if (i + x > n) {
                break;
            }

            taken += piles[i + x - 1];

            int opponent = f(
                i + x,
                max(m, x),
                dp,
                piles,
                suffix
            );

            // Total remaining - opponent's best
            int current =
                suffix[i] - opponent;

            ans = max(ans, current);
        }

        return dp[i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] =
                suffix[i + 1] + piles[i];
        }

        vector<vector<int>> dp(
            n,
            vector<int>(n + 1, -1)
        );

        return f(0, 1, dp, piles, suffix);
    }
};