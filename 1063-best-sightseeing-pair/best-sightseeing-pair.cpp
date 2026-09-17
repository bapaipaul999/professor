class Solution {
public:
    int f(int i, vector<int>& values, vector<int>& dp) {

        if (i == 0) {
            return values[0];
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        return dp[i] = max(
            values[i] + i,
            f(i - 1, values, dp)
        );
    }

    int maxScoreSightseeingPair(vector<int>& values) {

        int n = values.size();

        vector<int> dp(n, -1);

        int ans = 0;

        for (int j = 1; j < n; j++) {

            int bestLeft = f(j - 1, values, dp);

            ans = max(
                ans,
                bestLeft + values[j] - j
            );
        }

        return ans;
    }
};