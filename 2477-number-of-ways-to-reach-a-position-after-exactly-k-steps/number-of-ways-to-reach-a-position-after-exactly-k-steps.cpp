class Solution {
public:
    int MOD = 1e9 + 7;

    int f(int pos, int end, int k, vector<vector<int>>& dp, int offset) {
        if (k == 0) {
            return pos == end;
        }

        if (dp[pos + offset][k] != -1) {
            return dp[pos + offset][k];
        }

        int right = f(pos + 1, end, k - 1, dp, offset);
        int left = f(pos - 1, end, k - 1, dp, offset);

        return dp[pos + offset][k] =
            ((long long)right + left) % MOD;
    }

    int numberOfWays(int startPos, int endPos, int k) {
        int offset = k;
        int size = startPos + 2 * k + 1;

        vector<vector<int>> dp(size, vector<int>(k + 1, -1));

        return f(startPos, endPos, k, dp, offset);
    }
};