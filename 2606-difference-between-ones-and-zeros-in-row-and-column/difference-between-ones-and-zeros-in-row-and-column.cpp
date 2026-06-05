class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>row(m,0);
        vector<int>col(n,0);
        for(int i = 0 ; i<m ; i++){
            int ones = 0;
            int zeros = 0;
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] == 1){
                    ones++;
                }
                else{
                    zeros++;
                }
            }
            row[i] = ones-zeros;
        }
        for(int i = 0 ; i<n ; i++){
            int ones = 0;
            int zeros = 0;
            for(int j = 0 ; j<m ; j++){
                if(grid[j][i] == 1){
                    ones++;
                }
                else{
                    zeros++;
                }
            }
            col[i] = ones-zeros;
        }
        for(int i = 0 ; i<m ; i++){
            
            for(int j = 0 ; j<n ; j++){
                grid[i][j] = row[i] + col[j];
            }
            
        }
        return grid;

    }
};