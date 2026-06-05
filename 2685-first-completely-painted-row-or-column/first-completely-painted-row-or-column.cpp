class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        vector<pair<int, int>> ref(arr.size());

        unordered_map<int, pair<int,int>> mp;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[mat[i][j]] = {i, j};
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            ref[i] = mp[arr[i]];
        }

        for (int i = 0; i < arr.size(); i++) {

            row[ref[i].first]++;
            col[ref[i].second]++;

            if (row[ref[i].first] == n ||
                col[ref[i].second] == m) {
                return i;
            }
        }

        return -1;
    }
};