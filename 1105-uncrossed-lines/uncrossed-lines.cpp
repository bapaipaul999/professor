class Solution {
public:
    int f(int i1 , int i2 , vector<vector<int>>&dp ,vector<int>nums1, vector<int>nums2 ){
        if(i1 == 0 || i2 ==0 ){
            return 0;
        }
        if(dp[i1][i2]!=-1){
            return dp[i1][i2];
        }
        if(nums1[i1-1]==nums2[i2-1]){
            return dp[i1][i2] = 1+ f(i1-1 , i2-1 , dp , nums1 , nums2);
        }
        int notmatch1 = f(i1-1 , i2, dp , nums1 , nums2);
        int notmatch2 = f(i1 , i2-1 , dp , nums1 , nums2);
        return dp[i1][i2]  = max(notmatch1 , notmatch2) ;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));
        return f(n , m , dp , nums1 , nums2);
    }
};