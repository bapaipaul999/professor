class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int rowFlips = 0;
        int colFlips = 0;

        // Make every row a palindrome
        for (int i = 0; i < m; i++) {
            int l = 0;
            int r = n - 1;

            while (l < r) {
                if (grid[i][l] != grid[i][r]) {
                    rowFlips++;
                }

                l++;
                r--;
            }
        }

        // Make every column a palindrome
        for (int j = 0; j < n; j++) {
            int l = 0;
            int r = m - 1;

            while (l < r) {
                if (grid[l][j] != grid[r][j]) {
                    colFlips++;
                }

                l++;
                r--;
            }
        }

        return min(rowFlips, colFlips);
    }
};