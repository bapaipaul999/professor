class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> ref = board;
        vector<vector<int>> visited(m , vector<int>(n,0));

        queue<pair<int,int>>q1;
        for(int i = 0 ; i< m ; i++){
            for(int j = 0 ; j<n ; j++){
                if((i == 0 || i == m-1 || j == 0 || j == n-1)&&board[i][j] == 1){
                    q1.push({i,j});
                    visited[i][j] = 1;
                }
            }

        }
        vector<int> sr = {-1,0,1,0};
        vector<int> sc = {0,1,0,-1};
        while(!q1.empty()){
            int row = q1.front().first;
            int col = q1.front().second;
            q1.pop();
            ref[row][col] = 0;
            for(int i = 0; i<4 ; i++){
                int newrow = row + sr[i];
                int newcol = col +sc[i];
                if(newrow >= 0 && newrow < m &&
                   newcol >= 0 && newcol < n&&
                   visited[newrow][newcol] == 0&&board[newrow][newcol] == 1 ){
                        q1.push({newrow , newcol});
                        visited[newrow][newcol] = 1;
                   }
            }
        }
        int count = 0;
        for(int i = 0 ; i< m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(ref[i][j] == 1){
                    count++;
                }
            }

        }
        return count;
    }
};