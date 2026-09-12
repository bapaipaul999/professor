class Solution {
public:

    long long f(int i,
                vector<long long>& dp,
                vector<vector<int>>& jobs,
                vector<int>& next) {

        if (i == jobs.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        long long notTake = f(i + 1, dp, jobs, next);

        long long take =
            jobs[i][2] + f(next[i], dp, jobs, next);

        return dp[i] = max(take, notTake);
    }

    int jobScheduling(vector<int>& startTime,
                      vector<int>& endTime,
                      vector<int>& profit) {

        int n = startTime.size();

        vector<vector<int>> jobs;

        for (int i = 0; i < n; i++) {
            jobs.push_back({
                startTime[i],
                endTime[i],
                profit[i]
            });
        }

        // Sort jobs by start time
        sort(jobs.begin(), jobs.end());

        vector<int> starts(n);

        for (int i = 0; i < n; i++)
            starts[i] = jobs[i][0];

        vector<int> next(n);

        // Find next non-overlapping job
        for (int i = 0; i < n; i++) {

            int l = i + 1;
            int r = n;

            while (l < r) {

                int mid = l + (r - l) / 2;

                if (starts[mid] >= jobs[i][1])
                    r = mid;
                else
                    l = mid + 1;
            }

            next[i] = l;
        }

        vector<long long> dp(n + 1, -1);

        return f(0, dp, jobs, next);
    }
};