class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int start = 0;
            int end = m - 1;
            int mid = start + (end - start) / 2;
            int index = m;

            while (start <= end) {
                if (grid[i][mid] < 0) {
                    index = mid;
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
                mid = start + (end - start) / 2;
            }
            ans += (m - index);
        }
        return ans;
    }
};