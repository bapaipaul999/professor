class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0;
        long long ans = 0;
        int i = 0;

        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];

            while (i <= j && sum * (j - i + 1LL) >= k) {
                sum -= nums[i];
                i++;
            }

            ans += j - i + 1;
        }

        return ans;
    }
};