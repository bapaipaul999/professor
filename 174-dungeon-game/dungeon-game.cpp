class Solution {
public:

    int f(int m, int n, vector<vector<int>>& dp,
          vector<vector<int>>& dungeon) {

        int rows = dungeon.size();
        int cols = dungeon[0].size();

        // Out of bounds
        if (m >= rows || n >= cols) {
            return INT_MAX;
        }

        // Princess cell
        if (m == rows - 1 && n == cols - 1) {
            return max(1, 1 - dungeon[m][n]);
        }

        if (dp[m][n] != -1) {
            return dp[m][n];
        }

        // Go right
        int right = f(m, n + 1, dp, dungeon);

        // Go down
        int down = f(m + 1, n, dp, dungeon);

        // Choose the better path
        int need = min(right, down);

        // Health required before entering current cell
        int ans = need - dungeon[m][n];

        // Health can never be less than 1
        return dp[m][n] = max(1, ans);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return f(0, 0, dp, dungeon);
    }
};