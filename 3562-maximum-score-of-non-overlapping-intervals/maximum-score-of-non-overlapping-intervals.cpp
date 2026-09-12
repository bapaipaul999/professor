class Solution {
public:

    struct Node {
        long long score;
        vector<int> ids;
    };

    vector<vector<int>> a;
    vector<int> nxt;
    vector<vector<Node>> dp;
    vector<vector<bool>> vis;

    Node better(Node x, Node y) {

        if (x.score != y.score)
            return x.score > y.score ? x : y;

        return x.ids < y.ids ? x : y;
    }

    Node solve(int i, int k) {

        if (i == a.size() || k == 0)
            return {0, {}};

        if (vis[i][k])
            return dp[i][k];

        vis[i][k] = true;

        Node skip = solve(i + 1, k);

        Node take = solve(nxt[i], k - 1);

        take.score += a[i][2];

        take.ids.push_back(a[i][3]);

        sort(take.ids.begin(), take.ids.end());

        return dp[i][k] = better(skip, take);
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
            a.push_back(intervals[i]);
        }

        sort(a.begin(), a.end());

        vector<int> starts(n);

        for (int i = 0; i < n; i++)
            starts[i] = a[i][0];

        nxt.resize(n);

        for (int i = 0; i < n; i++) {

            int l = i + 1;
            int r = n;

            while (l < r) {

                int mid = l + (r - l) / 2;

                if (starts[mid] > a[i][1])
                    r = mid;
                else
                    l = mid + 1;
            }

            nxt[i] = l;
        }

        dp.resize(n, vector<Node>(5));
        vis.resize(n, vector<bool>(5, false));

        return solve(0, 4).ids;
    }
};