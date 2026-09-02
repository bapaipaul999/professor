class Solution {
public:
    long f(int idx, int buy, int trans, vector<vector<vector<int>>>& dp,
           vector<int> prices) {

        if (idx == prices.size() || trans == 0) {
            return 0;
        }

        if (dp[idx][buy][trans] != -1) {
            return dp[idx][buy][trans];
        }

        long profit = 0;

        if (buy) {
            profit = max(-prices[idx] + f(idx + 1, 0, trans, dp, prices),
                         f(idx + 1, 1, trans, dp, prices));
        } else {
            profit = max(prices[idx] + f(idx + 1, 1, trans - 1, dp, prices),
                         f(idx + 1, 0, trans, dp, prices));
        }

        return dp[idx][buy][trans] = profit;
    }

  int maxProfit(vector<int>& prices) {
    int n = prices.size();

    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(2, vector<int>(3, 0))
    );

    for (int idx = n - 1; idx >= 0; idx--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int trans = 1; trans <= 2; trans++) {

                long profit = 0;

                if (buy) {
                    profit = max(
                        -prices[idx] + dp[idx + 1][0][trans],
                        dp[idx + 1][1][trans]
                    );
                }
                else {
                    profit = max(
                        prices[idx] + dp[idx + 1][1][trans - 1],
                        dp[idx + 1][0][trans]
                    );
                }

                dp[idx][buy][trans] = profit;
            }
        }
    }

    return dp[0][1][2];
  }
};