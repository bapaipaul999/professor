class Solution {
public:
    int mod = 1e9 + 7;
    int dp[100005][2];

    int solve(int i, int parity, vector<int>& arr) {
        if (i == arr.size()) {
            return 0;
        }

        if (dp[i][parity] != -1) {
            return dp[i][parity];
        }

        int newParity = (parity + arr[i]) % 2;

        int ans = (newParity == 1);

        ans = (ans + solve(i + 1, newParity, arr)) % mod;

        return dp[i][parity] = ans;
    }

    int numOfSubarrays(vector<int>& arr) {
        memset(dp, -1, sizeof(dp));

        int ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            ans = (ans + solve(i, 0, arr)) % mod;
        }

        return ans;
    }
};