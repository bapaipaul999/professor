class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();

        vector<int> next_small(n);
        vector<int> prev_small(n);

        stack<int> st;

        // Next Smaller (strict)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            next_small[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Previous Smaller or Equal
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            prev_small[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        long long mod = 1e9 + 7;
        long long total = 0;

        for (int i = 0; i < n; i++) {

            long long left = i - prev_small[i];
            long long right = next_small[i] - i;

            total = (total + left * right % mod * arr[i]) % mod;
        }

        return total;
    }
};