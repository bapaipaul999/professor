class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> temp = board;   

        vector<int> offseti = {0,-1,-1,-1,0,1,1,1};
        vector<int> offsetj = {-1,-1,0,1,1,1,0,-1};

        int start = 0;
        int end = n*m - 1;

        while(start <= end){

            int i = start / m;
            int j = start % m;

            int sum1 = 0;

            for(int k = 0; k < 8; k++){
                int i1 = i + offseti[k];
                int j1 = j + offsetj[k];

                if(i1<0 || i1>=n || j1<0 || j1>=m) continue;

                sum1 += temp[i1][j1];   
            }

            if(temp[i][j] == 1){
                if(sum1 < 2 || sum1 > 3)
                    board[i][j] = 0;
            }
            else{
                if(sum1 == 3)
                    board[i][j] = 1;
            }


            int r = end / m;
            int t = end % m;

            sum1 = 0;

            for(int k = 0; k < 8; k++){
                int i1 = r + offseti[k];
                int j1 = t + offsetj[k];

                if(i1<0 || i1>=n || j1<0 || j1>=m) continue;

                sum1 += temp[i1][j1];   
            }

            if(temp[r][t] == 1){
                if(sum1 < 2 || sum1 > 3)
                    board[r][t] = 0;
            }
            else{
                if(sum1 == 3)
                    board[r][t] = 1;
            }

            start++;
            end--;
        }
    }
};
