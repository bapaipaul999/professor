class Solution {
public:
    vector<vector<int>> dp;
    vector<int> prefix;

    int solve(int l, int r) {
        if (l == r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        for (int i = l; i < r; i++) {
            int left = prefix[i + 1] - prefix[l];
            int right = prefix[r + 1] - prefix[i + 1];

            if (left < right) {
                ans = max(ans, left + solve(l, i));
            }
            else if (right < left) {
                ans = max(ans, right + solve(i + 1, r));
            }
            else {
                ans = max(ans, left + max(solve(l, i), solve(i + 1, r)));
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        prefix.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        dp.assign(n, vector<int>(n, -1));

        return solve(0, n - 1);
    }
};