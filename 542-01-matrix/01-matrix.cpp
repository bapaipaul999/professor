class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));

        queue<pair<pair<int,int>,int>> q1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(mat[i][j] == 0) {
                    visited[i][j] = 1;
                    q1.push({{i,j},0});
                }
            }
        }

        vector<int> sr = {-1,0,1,0};
        vector<int> sc = {0,1,0,-1};

        while(!q1.empty()) {

            int row = q1.front().first.first;
            int col = q1.front().first.second;
            int count = q1.front().second;

            q1.pop();

            ans[row][col] = count;

            for(int i = 0; i < 4; i++) {

                int newrow = row + sr[i];
                int newcol = col + sc[i];

                if(newrow >= 0 && newrow < n &&
                   newcol >= 0 && newcol < m &&
                   visited[newrow][newcol] == 0) {

                    visited[newrow][newcol] = 1;
                    q1.push({{newrow,newcol}, count + 1});
                }
            }
        }

        return ans;
    }
};