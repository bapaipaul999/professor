
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        // Precompute proper divisors for every length
        vector<vector<int>> divisors(n + 1);

        for (int d = 1; d < n; d++) {
            for (int len = 2 * d; len <= n; len += d) {
                divisors[len].push_back(d);
            }
        }

        // Calculate minimum changes for every substring
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len <= n; l++) {
                int r = l + len - 1;

                for (int d : divisors[len]) {
                    int changes = 0;

                    for (int i = 0; i < d; i++) {
                        int left = l + i;
                        int right = l + i + ((len - 1 - i) / d) * d;

                        while (left < right) {
                            if (s[left] != s[right])
                                changes++;

                            left += d;
                            right -= d;
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        // DP with rolling arrays
        vector<int> prev(n + 1, INF), curr(n + 1, INF);
        prev[0] = 0;

        for (int parts = 1; parts <= k; parts++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 2 * parts; i <= n; i++) {
                for (int j = 2 * (parts - 1); j <= i - 2; j++) {
                    if (prev[j] == INF) continue;

                    curr[i] = min(curr[i],
                                  prev[j] + cost[j][i - 1]);
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
