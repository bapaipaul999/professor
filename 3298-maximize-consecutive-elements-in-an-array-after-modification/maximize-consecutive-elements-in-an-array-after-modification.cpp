class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> dp;
        int ans = 0;

        for (int x : nums) {
            int prev1 = dp[x - 1];
            int prev2 = dp[x];

            dp[x] = max(dp[x], prev1 + 1);
            dp[x + 1] = max(dp[x + 1], prev2 + 1);

            ans = max(ans, max(dp[x], dp[x + 1]));
        }

        return ans;
    }
};