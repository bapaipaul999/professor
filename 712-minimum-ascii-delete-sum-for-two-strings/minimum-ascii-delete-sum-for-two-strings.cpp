class Solution {
public:
    int minimumDeleteSum(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] =
                        (int)text1[i - 1] + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] =
                        max(dp[i - 1][j],
                            dp[i][j - 1]);
                }
            }
        }

        int sum1 = 0;
        int sum2 = 0;

        for (char c : text1)
            sum1 += (int)c;

        for (char c : text2)
            sum2 += (int)c;

        return sum1 + sum2 - 2 * dp[n][m];
    }
};