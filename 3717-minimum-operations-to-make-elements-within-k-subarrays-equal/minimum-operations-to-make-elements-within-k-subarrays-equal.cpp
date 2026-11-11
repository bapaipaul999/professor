
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> low, high;
        long long sumLow = 0, sumHigh = 0;

        vector<long long> cost;

        auto balance = [&]() {
            while (low.size() > high.size() + 1) {
                int val = *low.rbegin();
                low.erase(prev(low.end()));
                sumLow -= val;

                high.insert(val);
                sumHigh += val;
            }

            while (low.size() < high.size()) {
                int val = *high.begin();
                high.erase(high.begin());
                sumHigh -= val;

                low.insert(val);
                sumLow += val;
            }
        };

        for (int i = 0; i < n; i++) {

            if (low.empty() || nums[i] <= *low.rbegin()) {
                low.insert(nums[i]);
                sumLow += nums[i];
            } else {
                high.insert(nums[i]);
                sumHigh += nums[i];
            }

            if (i >= x) {
                int val = nums[i - x];

                auto it = low.find(val);

                if (it != low.end()) {
                    low.erase(it);
                    sumLow -= val;
                } else {
                    it = high.find(val);
                    high.erase(it);
                    sumHigh -= val;
                }
            }

            balance();

            if (i >= x - 1) {
                long long median = *low.rbegin();

                long long c =
                    median * low.size() - sumLow +
                    sumHigh - median * high.size();

                cost.push_back(c);
            }
        }

        const long long INF = 1e18;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i][0] = 0;

            for (int j = 1; j <= k; j++) {

                dp[i][j] = dp[i - 1][j];

                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
