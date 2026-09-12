class Solution {
public:
    long long f(int n, vector<long long>& dp) {

        if (n <= 1) {
            return 1;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        long long ans = 0;

        for (int root = 1; root <= n; root++) {

            int left = root - 1;
            int right = n - root;

            ans += f(left, dp) * f(right, dp);
        }

        return dp[n] = ans;
    }

    int numTrees(int n) {

        vector<long long> dp(n + 1, -1);

        return f(n, dp);
    }
};