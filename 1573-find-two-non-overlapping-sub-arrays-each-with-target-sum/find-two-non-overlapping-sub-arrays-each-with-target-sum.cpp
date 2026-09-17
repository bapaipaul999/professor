class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> min_target_index(n, INT_MAX);

        int result = INT_MAX;

        int i = 0;
        int j = 0;

        int minlength = INT_MAX;
        int currentSum = 0;

        while (j < n) {
            currentSum += arr[j];

            while (currentSum > target && i <= j) {
                currentSum -= arr[i];
                i++;
            }

            if (currentSum == target) {
                int len = j - i + 1;

                if (i - 1 >= 0 && min_target_index[i - 1] != INT_MAX) {
                    result = min(result,
                                 len + min_target_index[i - 1]);
                }

                minlength = min(minlength, len);
            }

            min_target_index[j] = minlength;

            j++;
        }

        return result == INT_MAX ? -1 : result;
    }
};