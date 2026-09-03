class Solution {
public:
    // int f(int idx , int maxi , vector<vector<int>>&dp , vector<int>nums){
    //     if(idx == nums.size()){
    //         return 0;
    //     }
    //     if(dp[idx][maxi]!=-1){
    //         return dp[idx][maxi];
    //     }
    //     int notTake = f(idx+1 , maxi , dp , nums);
    //     int take = 0;
    //     if(nums[idx]%maxi == 0 || maxi%nums[idx]==0){
    //         take = 1+f(idx+1 , max(maxi , nums[idx]) , dp , nums);
    //     }
    //     return dp[idx][maxi] = max(notTake , take);
    // }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        // int m = *max_element(nums.begin() , nums.end());
        // vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));
        // return f(0 , 1 , dp , nums);

        int n = nums.size(); // Size of the array

        sort(nums.begin(), nums.end());

        vector<int> ans;       // To store the LDS
        vector<int> dp(n, 1);  // DP array
        vector<int> parent(n); // Array to keep record of the parent

        // To store the index of last element in the LDS
        int lastIndex = 0;

        // To store the length of LDS
        int maxLen = 0;

        // Computing the DP array
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Assign the parent to itself

            // For each previous index
            for (int prevInd = 0; prevInd < i; prevInd++) {

                // If the element at index i can be included in the LDS ending
                // at index j
                if (nums[i] % nums[prevInd] == 0 && dp[i] < dp[prevInd] + 1) {

                    dp[i] = dp[prevInd] + 1; // Update the DP value
                    parent[i] = prevInd;     // Store the parent
                }
            }

            // If a longer LDS is found, update the values
            if (dp[i] > maxLen) {
                lastIndex = i;
                maxLen = dp[i];
            }
        }

        // Backtracking
        int i = lastIndex;

        // Until we reach an index which is its own parent
        while (parent[i] != i) {
            ans.push_back(nums[i]); // Add the element at current index
            i = parent[i];
        }
        ans.push_back(nums[i]); // Adding the last element

        // Return the computed result
        return ans;
    }
};