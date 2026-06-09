class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mini = INT_MAX;
        int maxi = 0;

        for(int x : nums) {
            mini = min(mini, x);
            maxi = max(maxi, x);
        }

        return 1LL * (maxi - mini) * k;
    }
};