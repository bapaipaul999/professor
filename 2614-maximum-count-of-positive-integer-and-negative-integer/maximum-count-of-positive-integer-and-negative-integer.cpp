class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        // Find last negative
        int start = 0;
        int end = n - 1;
        int index1 = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] < 0) {
                index1 = mid;
                start = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }

        int negative = index1 + 1;

        // Find first positive
        start = 0;
        end = n - 1;
        int index2 = n;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] > 0) {
                index2 = mid;
                end = mid - 1;
            } 
            else {
                start = mid + 1;
            }
        }

        int positive = n - index2;

        return max(negative, positive);
    }
};