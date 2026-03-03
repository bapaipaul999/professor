class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int startingrow = 0;
        int startingcol = 0;
        int endingrow = row-1;
        int endingcol = col-1;
        vector<int>ans;
        int i = 0;
        int total = row*col;
        while(i<total){
            for(int j = startingcol ;i<total && j<=endingcol;j++){
                ans.push_back(matrix[startingrow][j]);
                i++;
            }
            startingrow++;
            for(int k = startingrow ;i<total && k<=endingrow;k++){
                ans.push_back(matrix[k][endingcol]);
                i++;
            }
            endingcol--;
            for(int j = endingcol ;i<total && j>=startingcol;j--){
                ans.push_back(matrix[endingrow][j]);
                i++;
            }
            endingrow--;
            for(int j = endingrow ;i<total && j>=startingrow;j--){
                ans.push_back(matrix[j][startingcol]);
                i++;
            }
            startingcol++;
        }
        return ans;
    }
};