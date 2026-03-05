class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
     vector<vector<int>> mat(n,vector<int>(n));
     int count = 0;
     int total = n*n;
     int startingrow = 0;
     int startingcol = 0;
     int endingrow = n-1;
     int endingcol = n-1;
     int value = 1;

     while(count < total){
        for(int i = startingcol ; i<= endingcol ; i++){
            mat[startingrow][i] = value;
            value++;
            count++;
        }
        startingrow++;
        for(int i = startingrow ; i<= endingrow ; i++){
            mat[i][endingcol] = value;
            value++;
            count++;
        }
        endingcol--;
        for(int i = endingcol ; i>= startingcol ; i--){
            mat[endingrow][i] = value;
            value++;
            count++;
        }
        endingrow--;
        for(int i = endingrow ; i>= startingrow ; i--){
            mat[i][startingcol] = value;
            value++;
            count++;
        }
        startingcol++;
        

     }
     return mat;

    }
};