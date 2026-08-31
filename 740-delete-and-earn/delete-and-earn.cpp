class Solution {
public:
    int f(int i, vector<int>& dp, const vector<int>& freq) {
        if (i >= freq.size()) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int notTake = f(i + 1, dp, freq);

        int take = freq[i] + f(i + 2, dp, freq);

        return dp[i] = max(take, notTake);
    }

    int deleteAndEarn(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> freq(maxi + 1, 0);

        for (auto x : nums) {
            freq[x] += x;
        }

        vector<int> dp(maxi + 1, -1);

        return f(0, dp, freq);
    }
};