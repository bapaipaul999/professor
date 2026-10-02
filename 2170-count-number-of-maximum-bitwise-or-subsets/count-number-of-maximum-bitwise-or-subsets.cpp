class Solution {
public:
    void f(int idx, int x, int& ans, int target, vector<int>& nums) {

        if(idx == nums.size()) {
            if(x == target) {
                ans++;
            }
            return;
        }

        // Don't take nums[idx]
        f(idx + 1, x, ans, target, nums);

        // Take nums[idx]
        f(idx + 1, x | nums[idx], ans, target, nums);
    }

    int countMaxOrSubsets(vector<int>& nums) {

        int target = 0;

        for(int x : nums) {
            target |= x;
        }

        int ans = 0;

        f(0, 0, ans, target, nums);

        return ans;
    }
};