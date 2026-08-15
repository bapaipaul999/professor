class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        int maxi = 0;
        map<int, int> mp;
        int left = 0;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            maxi++;

            while (mp[nums[i]] > k) {
                mp[nums[left]]--;
                maxi--;
                left++;
            }

            ans = max(ans, maxi);
        }

        return ans;
    }
};