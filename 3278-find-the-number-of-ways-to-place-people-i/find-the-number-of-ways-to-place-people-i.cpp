class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                // points[i] = upper-left
                // points[j] = lower-right
                if (i == j) continue;

                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                if (x1 > x2 || y1 < y2)
                    continue;

                bool valid = true;

                // Check if another point lies inside/on the rectangle
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j)
                        continue;

                    int x = points[k][0];
                    int y = points[k][1];

                    if (x >= x1 && x <= x2 &&
                        y >= y2 && y <= y1) {
                        valid = false;
                        break;
                    }
                }

                if (valid)
                    ans++;
            }
        }

        return ans;
    }
};