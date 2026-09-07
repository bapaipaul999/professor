class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        vector<long long> dp(26, 0);

        for (char c : s) {
            int x = c - 'a';

            long long sum = 0;

            for (int j = 0; j < 26; j++) {
                sum = (sum + dp[j]) % MOD;
            }

            dp[x] = (sum + 1) % MOD;
        }

        long long ans = 0;

        for (int i = 0; i < 26; i++) {
            ans = (ans + dp[i]) % MOD;
        }

        return ans;
    }
};