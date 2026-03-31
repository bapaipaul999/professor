class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0, max_sum = 0;
        unordered_map<int, int> check;

        while (right < nums.size()) {
            while (check[nums[right]] > 0) {
                check[nums[left]]--;
                sum -= nums[left];
                left++;
            }

            check[nums[right]]++;
            sum += nums[right];
            max_sum = max(max_sum, sum);
            right++;
        }

        return max_sum;
    }
};