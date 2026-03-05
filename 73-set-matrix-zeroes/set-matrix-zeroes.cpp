class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> temp = matrix;
        int n = matrix.size();
        int m = matrix[0].size();
        int start = 0;
        int end = n*m - 1;
        while(start <= end){
            int i = start /m ;
            int j = start%m;
            if(temp[i][j]==0){
                for(int k = 0 ; k<m ; k++){
                    matrix[i][k] = 0;
                }
                for(int k = 0 ; k<n ; k++){
                    matrix[k][j] = 0;
                }

            }
            i = end /m ;
            j = end%m;
            if(temp[i][j]==0){
                for(int k = 0 ; k<m ; k++){
                    matrix[i][k] = 0;
                }
                for(int k = 0 ; k<n ; k++){
                    matrix[k][j] = 0;
                }

            }
            start++;
            end--;
        }
    }
};