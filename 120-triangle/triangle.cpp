class Solution {
public:
    int f(int m , int n ,vector<vector<int>>& triangle , vector<vector<int>>& dp ){
        if(m == triangle.size()-1){
            return triangle[m][n];
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        int l = triangle[m][n] + f(m+1 , n , triangle, dp);
        int r = triangle[m][n] + f(m+1 , n+1 , triangle , dp);
        return dp[m][n] = min(l,r);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>>dp(m , vector<int>(n,-1));
        for(int i = 0 ; i<n ; i++){
            dp[m-1][i] = triangle[m-1][i];
        }

        for(int i = m-2 ; i>=0 ; i--){
            for(int j = i ; j>=0 ; j--){
                int l = dp[i+1][j] + triangle[i][j];
                int r = dp[i+1][j+1] + triangle[i][j];
                dp[i][j] = min(l , r);
            }
        }
        return dp[0][0];
    }
};