class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        string s2 = s;
        reverse(s2.begin(), s2.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        int maxLen = 0;
        int endIndex = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                if (s[i - 1] == s2[j - 1]) {

                    dp[i][j] = 1 + dp[i - 1][j - 1];

                    int len = dp[i][j];

                    // Start position in original string
                    int startIndex = i - len;

                    // Corresponding position in original string
                    int reverseStart = n - j;

                    // Check that both positions match
                    if (startIndex == reverseStart) {
                        if (len > maxLen) {
                            maxLen = len;
                            endIndex = i - 1;
                        }
                    }

                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return s.substr(endIndex - maxLen + 1, maxLen);
    }
};