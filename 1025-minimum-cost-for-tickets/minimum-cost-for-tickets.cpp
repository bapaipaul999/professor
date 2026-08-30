class Solution {
public:
    int n;
    vector<int> days, costs;
    vector<int> dp;

    int solve(int i) {
        // All travel days are covered
        if (i >= n)
            return 0;

        // Already calculated
        if (dp[i] != -1)
            return dp[i];

        // Option 1: Buy 1-day pass
        int cost1 = costs[0] + solve(i + 1);

        // Option 2: Buy 7-day pass
        int j = i;
        while (j < n && days[j] < days[i] + 7)
            j++;

        int cost7 = costs[1] + solve(j);

        // Option 3: Buy 30-day pass
        j = i;
        while (j < n && days[j] < days[i] + 30)
            j++;

        int cost30 = costs[2] + solve(j);

        return dp[i] = min({cost1, cost7, cost30});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->days = days;
        this->costs = costs;
        n = days.size();

        dp.assign(n, -1);

        return solve(0);
    }
};