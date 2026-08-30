class Solution {
public:
    bool f(int i1, int i2, int i3,
           vector<vector<vector<int>>>& dp,
           string s1, string s2, string s3) {

        // All characters are used
        if (i1 == 0 && i2 == 0 && i3 == 0) {
            return true;
        }

        // Length condition
        if (i1 + i2 != i3) {
            return false;
        }

        // Already calculated
        if (dp[i1][i2][i3] != -1) {
            return dp[i1][i2][i3];
        }

        dp[i1][i2][i3] = false;

        // Take character from s1
        if (i1 > 0 && s1[i1 - 1] == s3[i3 - 1]) {

            dp[i1][i2][i3] =
                f(i1 - 1, i2, i3 - 1,
                  dp, s1, s2, s3);
        }

        // Take character from s2
        if (i2 > 0 && s2[i2 - 1] == s3[i3 - 1]) {

            dp[i1][i2][i3] =
                dp[i1][i2][i3] ||
                f(i1, i2 - 1, i3 - 1,
                  dp, s1, s2, s3);
        }

        return dp[i1][i2][i3];
    }

    bool isInterleave(string s1, string s2, string s3) {

        int n = s1.size();
        int m = s2.size();
        int x = s3.size();

        if (n + m != x) {
            return false;
        }

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(
                m + 1,
                vector<int>(x + 1, -1)
            )
        );

        return f(n, m, x, dp, s1, s2, s3);
    }
};