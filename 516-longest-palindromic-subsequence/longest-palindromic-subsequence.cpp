class Solution {
public:
    int f(int start, int end, vector<vector<int>>& dp, string s) {
        if (start > end) {
            return 0;
        }
        if (start == end) {
            return 1;
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        if (s[start] == s[end]) {
            return dp[start][end] = 2 + f(start + 1, end - 1, dp, s);
        }
        return dp[start][end] =
                   max(f(start + 1, end, dp, s), f(start, end - 1, dp, s));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        // Make a copy of s
        string s2 = s;

        // Reverse the copy
        reverse(s2.begin(), s2.end());

        // DP table for LCS
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                if (s[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][n];
    }
};