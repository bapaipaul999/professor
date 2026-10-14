class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        if (nums.size() < 3) {
            return 0;
        }
        int diff = nums[1] - nums[0];
        int i = 0;
        int j = 1;
        int ans = 0;
        while (j < nums.size()) {
            if (nums[j] - nums[j - 1] == diff) {
                int x = i;
                while (j - x >= 3) {
                    ans++;
                    x++;
                }
                j++;
            } else {
                while (j - i >= 3) {
                    ans++;
                    i++;
                }
                i = j - 1;
                diff = nums[j] - nums[i];
                j++;
            }
        }
        while (j - i >= 3) {
            ans++;
            i++;
        }
        return ans;
    }
};