class Solution {
public:
    int f(int n , vector<int>&dp){
        if(n==0){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int lh =f(n-1 , dp);
        int rh = 0;
        if(n>1){
            rh = f(n-2 , dp);
        } 
        return dp[n] = lh + rh;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1 , -1);
        return f(n , dp);
    }
};