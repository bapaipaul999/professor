class Solution {
public:
    long long f(int i, vector<long long>& dp, vector<vector<int>>& rides,
                vector<int>& next) {

        if (i == rides.size()) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        long long notTake = f(i + 1, dp, rides, next);

        long long take = rides[i][1] - rides[i][0] + rides[i][2]
                       + f(next[i], dp, rides, next);

        return dp[i] = max(take, notTake);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {

        int m = rides.size();

        sort(rides.begin(), rides.end());

        vector<int> next(m);

        for (int i = 0; i < m; i++) {

            int start = i + 1;
            int end = m;

            while (start < end) {

                int mid = start + (end - start) / 2;

                if (rides[mid][0] >= rides[i][1]) {
                    end = mid;
                }
                else {
                    start = mid + 1;
                }
            }

            next[i] = start;
        }

        vector<long long> dp(m + 1, -1);

        return f(0, dp, rides, next);
    }
};