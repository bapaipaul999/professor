class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector<int> next_small(n);
        vector<int> prev_small(n);
        stack<int> s1;

      
        for (int i = n - 1; i >= 0; i--) {
            while (!s1.empty() && nums[s1.top()] > nums[i]) {
                s1.pop();
            }

            if (s1.empty()) {
                next_small[i] = n;
            } else {
                next_small[i] = s1.top();
            }

            s1.push(i);
        }

        while (!s1.empty()) s1.pop();

       
        for (int i = 0; i < n; i++) {
            while (!s1.empty() && nums[s1.top()] >= nums[i]) {
                s1.pop();
            }

            if (s1.empty()) {
                prev_small[i] = -1;
            } else {
                prev_small[i] = s1.top();
            }

            s1.push(i);
        }

        long long mod = 1e9 + 7;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prev_small[i];
            long long right = next_small[i] - i;
            long long freq = left * right;

            sum = (sum + (freq * nums[i]) % mod) % mod;
        }

        return sum;
    }
};