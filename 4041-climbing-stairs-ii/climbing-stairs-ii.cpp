class Solution {
public:
    int f(int i, vector<int>& dp, vector<int> costs) {
        if (i == costs.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int i1 = INT_MAX;
        int i2 = INT_MAX;
        int i3 = INT_MAX;
        if (i + 1 <= costs.size()) {
            i1 = costs[i] + pow(1, 2) + f(i + 1, dp, costs);
        }
        if (i + 2 <= costs.size()) {
            i2 = costs[i + 1] + pow(2, 2) + f(i + 2, dp, costs);
        }
        if (i + 3 <= costs.size()) {
            i3 = costs[i + 2] + pow(3, 2) + f(i + 3, dp, costs);
        }
        return dp[i] = min(i1, min(i2, i3));
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, 0);
        // return f(0, dp, costs);

        for (int i = n - 1; i >= 0; i--) {
            int i1 = INT_MAX;
            int i2 = INT_MAX;
            int i3 = INT_MAX;
            if (i + 1 <= costs.size()) {
                i1 = costs[i] + pow(1, 2)+ dp[i+1];
            }
            if (i + 2 <= costs.size()) {
                i2 = costs[i + 1] + pow(2, 2) + dp[i+2];
            }
            if (i + 3 <= costs.size()) {
                i3 = costs[i + 2] + pow(3, 2) + dp[i+3];
            }
            dp[i] = min(i1, min(i2, i3));
        }
        return dp[0];
    }
};