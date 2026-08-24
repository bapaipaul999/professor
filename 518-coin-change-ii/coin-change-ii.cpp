class Solution {
public:
     int f(int n, int target, vector<vector<int>>& dp, vector<int>& coins) {

        if(target == 0) {
            return 1;
        }

        if(n == 0) {
            if(target % coins[0] == 0) {
                return 1;
            }
            return 0;
        }

        if(dp[n][target] != -1) {
            return dp[n][target];
        }

        // Don't take coin[n]
        int notTake = f(n - 1, target, dp, coins);

        int take = 0;
        

        if(coins[n] <= target) {

            // Take coin[n] and stay at same index
            take = f(n, target - coins[n], dp, coins);

           
        }

        return dp[n][target] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
                int n = coins.size();

        vector<vector<int>> dp(
            n,
            vector<int>(amount + 1, -1)
        );
        return f(n-1 , amount , dp , coins);

    }
};