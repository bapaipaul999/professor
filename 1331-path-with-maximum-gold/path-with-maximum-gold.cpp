class Solution {
public:
    int ans = 0;
    int m, n;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void f(int i, int j, vector<vector<int>>& grid, int sum) {
        ans = max(ans, sum);

        int gold = grid[i][j];
        grid[i][j] = 0;  // Mark as visited

        for (int d = 0; d < 4; d++) {
            int x = i + dx[d];
            int y = j + dy[d];

            if (x >= 0 && x < m && y >= 0 && y < n &&
                grid[x][y] > 0) {
                f(x, y, grid, sum + grid[x][y]);
            }
        }

        grid[i][j] = gold;  // Backtrack
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    f(i, j, grid, grid[i][j]);
                }
            }
        }

        return ans;
    }
};