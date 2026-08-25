class Solution {
public:
    int f(int n, vector<int>& dp) {
        if (n == 0) {
            return 1;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        int lh = f(n - 1, dp);
        int rh = 0;
        if (n > 1) {
            rh = f(n - 2, dp);
        }
        return dp[n] = lh + rh;
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        
        dp[0] = 1;
        dp[1] =1;
        for (int i = 2; i <= n; i++) {
            int lh = dp[i-1];
            int rh= dp[i-2];
            
            dp[i] = lh + rh;
        }
        return dp[n];
    }
};