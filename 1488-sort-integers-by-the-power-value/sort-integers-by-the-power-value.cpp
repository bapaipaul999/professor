class Solution {
public:

    int power(int n, unordered_map<int, int>& dp) {

        if (n == 1)
            return 0;

        if (dp.count(n))
            return dp[n];

        if (n % 2 == 0)
            return dp[n] = 1 + power(n / 2, dp);

        return dp[n] = 1 + power(3 * n + 1, dp);
    }

    int getKth(int lo, int hi, int k) {

        unordered_map<int, int> dp;

        vector<pair<int, int>> v;

        for (int i = lo; i <= hi; i++) {
            v.push_back({power(i, dp), i});
        }

        sort(v.begin(), v.end());

        return v[k - 1].second;
    }
};