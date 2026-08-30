class Solution {
public:
    int f(int i1, int i2, vector<vector<int>>& dp, string s, string p) {

        // Both are exhausted
        if (i1 == 0 && i2 == 0) {
            return true;
        }

        // String exhausted
        // Pattern must contain only '*'
        if (i1 == 0) {
            while (i2 > 0) {
                if (p[i2 - 1] != '*') {
                    return false;
                }
                i2--;
            }
            return true;
        }

        // Pattern exhausted but string is not
        if (i2 == 0) {
            return false;
        }

        if (dp[i1][i2] != -1) {
            return dp[i1][i2];
        }

        // Same character OR '?'
        if (s[i1 - 1] == p[i2 - 1] || p[i2 - 1] == '?') {
            return dp[i1][i2] = f(i1 - 1, i2 - 1, dp, s, p);
        }

        // '*'
        if (p[i2 - 1] == '*') {

            // '*' matches empty
            bool notTake = f(i1, i2 - 1, dp, s, p);

            // '*' matches current character
            bool take = f(i1 - 1, i2, dp, s, p);

            return dp[i1][i2] = notTake || take;
        }

        // Characters don't match
        return dp[i1][i2] = false;
    }

    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Both empty
        dp[0][0] = 1;

        // String is empty
        // Pattern should contain only '*'
        for (int i2 = 1; i2 <= m; i2++) {

            if (p[i2 - 1] == '*') {
                dp[0][i2] = dp[0][i2 - 1];
            } else {
                dp[0][i2] = 0;
            }
        }

        // Pattern is empty
        // String is not empty -> false
        for (int i1 = 1; i1 <= n; i1++) {
            dp[i1][0] = 0;
        }

        // Fill the table
        for (int i1 = 1; i1 <= n; i1++) {

            for (int i2 = 1; i2 <= m; i2++) {

                // Same character OR '?'
                if (s[i1 - 1] == p[i2 - 1] || p[i2 - 1] == '?') {

                    dp[i1][i2] = dp[i1 - 1][i2 - 1];
                }

                // '*'
                else if (p[i2 - 1] == '*') {

                    // '*' matches empty
                    bool notTake = dp[i1][i2 - 1];

                    // '*' matches current character
                    bool take = dp[i1 - 1][i2];

                    dp[i1][i2] = notTake || take;
                }

                // No match
                else {
                    dp[i1][i2] = 0;
                }
            }
        }

        return dp[n][m];
    }
};