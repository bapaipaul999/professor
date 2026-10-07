class Solution {
public:
    vector<vector<int>> ans;

    void f(int idx, int k, int n, vector<int>& temp, int& sum) {

        if (sum > n)
            return;

        if ((int)temp.size() == k) {
            if (sum == n) {
                ans.push_back(temp);
            }
            return;
        }
        if (idx == 10)
            return;

        // Don't take idx
        f(idx + 1, k, n, temp, sum);

        // Take idx
        temp.push_back(idx);
        sum += idx;

        f(idx + 1, k, n, temp, sum);

        // Backtrack
        sum -= idx;
        temp.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        int sum = 0;

        f(1, k, n, temp, sum);

        return ans;
    }
};