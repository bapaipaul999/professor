class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, int remain) {

        // Out of bounds / obstacle
        if(i < 0 || i >= grid.size() ||
           j < 0 || j >= grid[0].size() ||
           grid[i][j] == -1) {
            return 0;
        }

        // Reached ending cell
        if(grid[i][j] == 2) {
            return remain == 1;
        }

        // Mark current cell visited
        grid[i][j] = -1;

        int ans = 0;

        ans += f(i + 1, j, grid, remain - 1);
        ans += f(i - 1, j, grid, remain - 1);
        ans += f(i, j + 1, grid, remain - 1);
        ans += f(i, j - 1, grid, remain - 1);

        // Backtrack
        grid[i][j] = 0;

        return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {

        int si = 0, sj = 0;
        int remain = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {

                if(grid[i][j] != -1) {
                    remain++;
                }

                if(grid[i][j] == 1) {
                    si = i;
                    sj = j;
                }
            }
        }

        return f(si, sj, grid, remain);
    }
};