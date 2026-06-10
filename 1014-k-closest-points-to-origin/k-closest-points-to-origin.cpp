class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        for (int i = 0; i < points.size(); i++) {
            int x = pow(points[i][0], 2) + pow(points[i][1], 2);
           
            pq.push({x, {points[i][0], points[i][1]}});
        }
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};