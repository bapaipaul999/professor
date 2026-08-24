class Solution {
public:
    int f(int n, int target, vector<vector<int>>& dp, vector<int>& coins) {

        if(target == 0) {
            return 0;
        }

        if(n == 0) {
            if(target % coins[0] == 0) {
                return target / coins[0];
            }
            return 1e9;
        }

        if(dp[n][target] != -1) {
            return dp[n][target];
        }

        // Don't take coin[n]
        int notTake = f(n - 1, target, dp, coins);

        int take1 = 1e9;
        int take2 = 1e9;

        if(coins[n] <= target) {

            // Take coin[n] and stay at same index
            take1 = 1 + f(n, target - coins[n], dp, coins);

            // Take coin[n] and move to previous index
            take2 = 1 + f(n - 1, target - coins[n], dp, coins);
        }

        return dp[n][target] = min({notTake, take1, take2});
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(
            n,
            vector<int>(amount + 1, 0)
        );

        
         for(int j = 0; j <= amount; j++) {

            if(j % coins[0] == 0) {
                dp[0][j] = j / coins[0];
            }
            else {
                dp[0][j] = 1e9;
            }
        }


        for(int i = 1 ; i<n ; i++){
            for(int j = 0 ; j<=amount ; j++){
                int notTake = dp[i-1][j];
                int take = 1e9;
                if(coins[i]<=j){
                    take = 1 + dp[i][j-coins[i]];
                }
                dp[i][j] = min(take , notTake);
            }
        }

        int ans = dp[n-1][amount];

        if(ans >= 1e9) {
            return -1;
        }

        return ans;
    }
};