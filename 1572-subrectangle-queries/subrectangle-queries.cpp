class SubrectangleQueries {
public:
    vector<vector<int>> ans;

    SubrectangleQueries(vector<vector<int>>& rectangle) {
        ans = rectangle;
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {

        for(int i = 0; i < ans.size(); i++) {
            for(int j = 0; j < ans[0].size(); j++) {

                if(i >= row1 && i <= row2 &&
                   j >= col1 && j <= col2) {

                    ans[i][j] = newValue;
                }
            }
        }
    }

    int getValue(int row, int col) {
        return ans[row][col];
    }
};
/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */