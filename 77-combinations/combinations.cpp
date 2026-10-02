class Solution {
public:
    void f(int idx, int k, vector<int>& temp,
           vector<vector<int>>& ans, int n) {

        if(k == 0) {
            ans.push_back(temp);
            return;
        }

        // Not enough numbers left
        if(idx > n || n - idx + 1 < k) {
            return;
        }

        // Don't take idx
        f(idx + 1, k, temp, ans, n);

        // Take idx
        temp.push_back(idx);

        f(idx + 1, k - 1, temp, ans, n);

        // Backtrack
        temp.pop_back();
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;

        f(1, k, temp, ans, n);

        return ans;
    }
};