class Solution {
public:
    int f(int idx, int prev, vector<vector<int>>& dp, vector<int> nums) {
        if (idx == nums.size()) {
            return 0;
        }
        if (dp[idx][prev] != -1) {
            return dp[idx][prev];
        }
        int nottake = f(idx + 1, prev, dp, nums);
        int take = 0;
        if (prev == 0 || nums[idx] > nums[prev - 1]) {
            take = 1 + f(idx + 1, idx + 1, dp, nums);
        }
        return dp[idx][prev] = max(take, nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // for (int idx = n - 1; idx >= 0; idx--) {
        //     for (int prev = 0; prev <= n; prev++) {

        //         int nottake = dp[idx + 1][prev];

        //         int take = 0;

        //         if (prev == 0 || nums[idx] > nums[prev - 1]) {
        //             take = 1 + dp[idx + 1][idx + 1];
        //         }

        //         dp[idx][prev] = max(take, nottake);
        //     }
        // }

        // return dp[0][0];

        // return f(0, 0, dp, nums);


        vector<int>temp;
        int maxi = 1;
        temp.push_back(nums.front());
        for(int i = 1 ; i<nums.size() ; i++){
            if(nums[i]>temp.back()){
                maxi++;
                temp.push_back(nums[i]);
            }
            else{
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
        }
        return maxi;
    }
};