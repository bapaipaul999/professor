class Solution {
public:

    int f(int i, string &s, vector<int> &dp) {

        if (i < 0)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        // A valid substring cannot end with '('
        if (s[i] == '(')
            return dp[i] = 0;

        // Case 1: "()"
        if (i > 0 && s[i - 1] == '(') {

            dp[i] = 2 + f(i - 2, s, dp);

            return dp[i];
        }

        // Case 2: "...))"
        int prev = f(i - 1, s, dp);

        int j = i - prev - 1;

        if (j >= 0 && s[j] == '(') {

            dp[i] = prev + 2 + f(j - 1, s, dp);
        }
        else {
            dp[i] = 0;
        }

        return dp[i];
    }

    int longestValidParentheses(string s) {

        int n = s.size();

        vector<int> dp(n, -1);

        int ans = 0;

        for (int i = 0; i < n; i++) {

            ans = max(ans, f(i, s, dp));
        }

        return ans;
    }
};