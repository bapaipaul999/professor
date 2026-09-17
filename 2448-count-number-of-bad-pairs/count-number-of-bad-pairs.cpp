class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        long long n = nums.size();

        // Total number of pairs
        long long totalPairs = n * (n - 1) / 2;

        unordered_map<long long, long long> mp;

        long long goodPairs = 0;

        for (long long i = 0; i < n; i++) {

            long long value = nums[i] - i;

            // Previous indices having same nums[i] - i
            goodPairs += mp[value];

            mp[value]++;
        }

        return totalPairs - goodPairs;
    }
};