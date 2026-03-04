class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int count = 0;
        for(int i = 0 ;i<n ; i++ ){
            count = count + mat[i][i] + mat[i][n-1-i];
        }
        if(n%2!=0){
            count = count - mat[n/2][n/2];
        }
        return count;
    }
};