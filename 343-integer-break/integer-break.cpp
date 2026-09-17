class Solution {
public:
    int f(int i, int n, vector<int>& dp) {

        if (i == n) {
            return 1;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int ans = 0;

        for (int j = i + 1; j <= n; j++) {

            int x = j - i;

            // Don't allow taking the entire n as one piece
            if (i == 0 && j == n) {
                continue;
            }

            ans = max(ans, x * f(j, n, dp));
        }

        return dp[i] = ans;
    }

    int integerBreak(int n) {

        vector<int> dp(n + 1, -1);

        return f(0, n, dp);
    }
};