class Solution {
public:
    long f(int idx, int buy, vector<vector<int>>& dp, vector<int> prices , int fee) {
        if (idx == prices.size()) {
            return 0;
        }

        if (dp[idx][buy] != -1) {
            return dp[idx][buy];
        }

        long profit = 0;

        if (buy) {
            profit = max(-prices[idx] + f(idx + 1, 0, dp, prices , fee),
                         f(idx + 1, 1, dp, prices , fee));
        } else {
            profit = max(prices[idx]-fee + f(idx + 1, 1, dp, prices , fee),
                         f(idx + 1, 0, dp, prices , fee));
        }

        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices , int fee) {
         int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        dp[n][0] = dp[n][1] = 0;

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {

                long profit = 0;

                if (buy) {
                    profit = max(
                        -prices[idx] + dp[idx + 1][0],
                        dp[idx + 1][1]
                    );
                }
                else {
                    profit = max(
                        prices[idx] - fee+ dp[idx + 1][1],
                        dp[idx + 1][0]
                    );
                }

                dp[idx][buy] = profit;
            }
        }

        return dp[0][1];
    }
};