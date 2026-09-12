class Solution {
public:

    long long f(int i, int k,
                vector<vector<long long>>& dp,
                vector<vector<int>>& events,
                vector<int>& next) {

        if (i == events.size() || k == 0)
            return 0;

        if (dp[i][k] != -1)
            return dp[i][k];

        long long notTake = f(i + 1, k, dp, events, next);

        long long take =
            events[i][2] + f(next[i], k - 1, dp, events, next);

        return dp[i][k] = max(take, notTake);
    }

    int maxTwoEvents(vector<vector<int>>& events) {

        int n = events.size();

        sort(events.begin(), events.end());

        vector<int> start(n);

        for (int i = 0; i < n; i++)
            start[i] = events[i][0];

        vector<int> next(n);

        for (int i = 0; i < n; i++) {

            int l = i + 1;
            int r = n;

            while (l < r) {

                int mid = l + (r - l) / 2;

                if (start[mid] > events[i][1])
                    r = mid;
                else
                    l = mid + 1;
            }

            next[i] = l;
        }

        vector<vector<long long>> dp(
            n + 1,
            vector<long long>(3, -1)
        );

        return f(0, 2, dp, events, next);
    }
};