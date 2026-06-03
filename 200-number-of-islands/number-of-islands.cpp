class Solution {
public:

    void bfs(int row, int col,
             vector<vector<int>>& visited,
             vector<vector<char>>& grid) {

        visited[row][col] = 1;

        queue<pair<int,int>> q1;
        q1.push({row,col});

        int n = grid.size();
        int m = grid[0].size();

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q1.empty()) {

            int r = q1.front().first;
            int c = q1.front().second;
            q1.pop();

            for(int k = 0; k < 4; k++) {

                int newRow = r + dr[k];
                int newCol = c + dc[k];

                if(newRow >= 0 &&
                   newRow < n &&
                   newCol >= 0 &&
                   newCol < m &&
                   visited[newRow][newCol] == 0 &&
                   grid[newRow][newCol] == '1') {

                    visited[newRow][newCol] = 1;
                    q1.push({newRow,newCol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        int count = 0;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(visited[i][j] == 0 &&
                   grid[i][j] == '1') {

                    count++;
                    bfs(i, j, visited, grid);
                }
            }
        }

        return count;
    }
};