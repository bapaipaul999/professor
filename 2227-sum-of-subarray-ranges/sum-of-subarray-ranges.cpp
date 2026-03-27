class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> next_small(n), prev_small(n);
        vector<int> next_b(n), prev_b(n);
        stack<int> s1;

        // ---------- MINIMUM ----------
        // Next Smaller
        for (int i = n - 1; i >= 0; i--) {
            while (!s1.empty() && nums[s1.top()] > nums[i]) {
                s1.pop();
            }

            if (s1.empty()) next_small[i] = n;
            else next_small[i] = s1.top();

            s1.push(i);
        }

        while (!s1.empty()) s1.pop();

        // Previous Smaller
        for (int i = 0; i < n; i++) {
            while (!s1.empty() && nums[s1.top()] >= nums[i]) {
                s1.pop();
            }

            if (s1.empty()) prev_small[i] = -1;
            else prev_small[i] = s1.top();

            s1.push(i);
        }

        while (!s1.empty()) s1.pop();

        // ---------- MAXIMUM ----------
        // Previous Greater
        for (int i = 0; i < n; i++) {
            while (!s1.empty() && nums[s1.top()] <= nums[i]) {
                s1.pop();
            }

            if (s1.empty()) prev_b[i] = -1;
            else prev_b[i] = s1.top();

            s1.push(i);
        }

        while (!s1.empty()) s1.pop();

        // Next Greater
        for (int i = n - 1; i >= 0; i--) {
            while (!s1.empty() && nums[s1.top()] < nums[i]) {
                s1.pop();
            }

            if (s1.empty()) next_b[i] = n;
            else next_b[i] = s1.top();

            s1.push(i);
        }

        long long sum1 = 0; // min contribution
        long long sum2 = 0; // max contribution

        for (int i = 0; i < n; i++) {
            long long left = i - prev_small[i];
            long long right = next_small[i] - i;
            long long freq = left * right;
            sum1 += freq * nums[i];

            left = i - prev_b[i];
            right = next_b[i] - i;
            freq = left * right;
            sum2 += freq * nums[i];
        }

        return sum2 - sum1;
    }
};