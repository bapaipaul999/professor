class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int>ans(n*m);
        for(int i = 0 ; i< ans.size(); i++){
            int val1 = grid[i/m][i%m];
            ans[(i+k)%ans.size()] = val1;
        }
        for(int i = 0; i< ans.size() ; i++){
            grid[i/m][i%m] = ans[i];
        }
        return grid;
       
    }
};