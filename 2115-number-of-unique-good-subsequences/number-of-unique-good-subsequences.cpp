class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        const int MOD = 1e9 + 7;

        long long f = 0;
        long long g = 0;
        long long zero = 0;

        for (char c : binary) {
            if (c == '0') {
                g = (g + f) % MOD;
                zero = 1;
            } 
            else {
                f = (f + g + 1) % MOD;
            }
        }

        return (f + g + zero) % MOD;
    }
};