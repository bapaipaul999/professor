class Solution {
public:
    static bool comparasion(vector<int> first, vector<int> second) {
        return first[0] < second[0];
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end(), comparasion);

        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {

            if (ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
            }
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};