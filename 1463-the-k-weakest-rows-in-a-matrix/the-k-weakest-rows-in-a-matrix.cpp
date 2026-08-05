class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        for (int i = 0; i < n; i++) {
            int start = 0;
            int end = m - 1;

            while (start <= end) {
                int mid = start + (end - start) / 2;

                if (mat[i][mid] == 0) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }

            // start = number of soldiers
            pq.push({start, i});
        }

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};