class Solution {
public:
    long long f(int i , vector<long long>&dp ,vector<vector<int>>& questions ){
        if(i>=questions.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long take = questions[i][0] + f(i+1+questions[i][1] , dp , questions);
        long long  notTake = f(i+1 , dp , questions);
        return dp[i] = max(take , notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n , -1);
        return f(0 , dp , questions);
    }
};