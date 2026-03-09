class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> matrix1(n, vector<int>(n));
        int start = 0;
        int end = n*n -1;
        while(start <= end){
            int i = start/n;
            int j = start%n;
            matrix1[j][n-i-1] = matrix[i][j];
            i = end/n;
            j = end%n;
            matrix1[j][n-i-1] = matrix[i][j];
            start++ ;
            end--;

        }


        matrix = matrix1;
    }
};
