class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        vector<int> next_small(n);
        vector<int> prev_small(n);
        stack<int> s1;

        // Next Smaller
        for (int i = n - 1; i >= 0; i--) {
            while (!s1.empty() && nums[s1.top()] >= nums[i]) {
                s1.pop();
            }
            if (s1.empty()) {
                next_small[i] = n;
            } else {
                next_small[i] = s1.top();
            }
            s1.push(i);
        }

        while (!s1.empty()) {
            s1.pop();
        }

        // Previous Smaller
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

        int maxi = 0;

        for (int i = 0; i < n; i++) {
            int width = next_small[i] - prev_small[i] - 1;
            int area = width * nums[i];
            maxi = max(maxi, area);
        }

        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& nums) {
        if (nums.empty()) return 0;

        int n = nums.size();
        int m = nums[0].size();

        vector<int> ans(m, 0);
        int max_area = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums[i][j] == '1') {
                    ans[j]++;
                } else {
                    ans[j] = 0;
                }
            }

            int largest = largestRectangleArea(ans);
            max_area = max(max_area, largest);
        }

        return max_area;
    }
};