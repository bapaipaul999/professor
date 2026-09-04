class Solution {
public:

    int f(int x) {
        vector<int> nums;

        while (x > 0) {
            nums.push_back(x % 10);
            x /= 10;
        }

        int n = nums.size();

        if (n < 3) {
            return 0;
        }

        int ans = 0;

        for (int i = 1; i < n - 1; i++) {

            if ((nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) ||
                (nums[i] < nums[i - 1] && nums[i] < nums[i + 1])) {
                ans++;
            }
        }

        return ans;
    }

    int totalWaviness(int num1, int num2) {

        int ans = 0;

        for (int i = num1; i <= num2; i++) {
            ans += f(i);
        }

        return ans;
    }
};