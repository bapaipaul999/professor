class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        int ans = 0;
        int n = citations.size();

        for (int i = 1; i <= n; i++) {
            int j = 0;

            while (j < n && citations[j] < i) {
                j++;
            }

            if (n - j >= i) {
                ans = max(ans, i);
            }
        }

        return ans;
    }
};