class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k);

        // dp[r] = number of subarrays ending at current position
        // whose product % k == r
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> newDp(k, 0);

            int x = num % k;

            // Start a new subarray with only num
            newDp[x] = 1;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                int newR = (1LL * r * x) % k;
                newDp[newR] += dp[r];
            }

            // Add all subarrays ending here to answer
            for (int r = 0; r < k; r++) {
                ans[r] += newDp[r];
            }

            dp = newDp;
        }

        return ans;
    }
};