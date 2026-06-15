class Solution {
public:
    vector<int> searchRange(vector<int>& candles, int front, int back) {
        int first = -1;
        int last = -1;

        int start = 0, end = candles.size() - 1;

        // first candle >= front
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (candles[mid] >= front) {
                first = candles[mid];
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        start = 0;
        end = candles.size() - 1;

        // last candle <= back
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (candles[mid] <= back) {
                last = candles[mid];
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return {first, last};
    }

    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> temp(n + 1, 0);

        for (int i = 0; i < n; i++) {
            temp[i + 1] = temp[i] + (s[i] == '*');
        }

        vector<int> candles;
        for (int i = 0; i < n; i++) {
            if (s[i] == '|')
                candles.push_back(i);
        }

        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {

            auto range = searchRange(
                candles,
                queries[i][0],
                queries[i][1]
            );

            int first = range[0];
            int last = range[1];

            if (first == -1 || last == -1 || first >= last) {
                ans.push_back(0);
                continue;
            }

            ans.push_back(temp[last] - temp[first]);
        }

        return ans;
    }
};