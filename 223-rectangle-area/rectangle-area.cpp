class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1,
                    int bx2, int by2) {

        bool xOverlap = ax1 < bx2 && bx1 < ax2;
        bool yOverlap = ay1 < by2 && by1 < ay2;

        int area = abs(ax1 - ax2) * abs(ay1 - ay2)
                 + abs(bx1 - bx2) * abs(by1 - by2);

        vector<int> x;
        x.push_back(ax1);
        x.push_back(ax2);
        x.push_back(bx1);
        x.push_back(bx2);

        vector<int> y;
        y.push_back(ay1);
        y.push_back(ay2);
        y.push_back(by1);
        y.push_back(by2);

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        if (xOverlap && yOverlap) {
            int area2 = abs(x[1] - x[2]) * abs(y[1] - y[2]);
            area -= area2;
        }

        return area;
    }
};