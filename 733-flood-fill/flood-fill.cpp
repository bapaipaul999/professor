class Solution {
public:
    void dfs(int row , int col ,vector<vector<int>> image,vector<vector<int>>& arr,int newcolor , int color ){
        arr[row][col] = color;
        int sr[4] = {-1,0,1,0};
        int sc[4] = {0,1,0,-1};
        int n = image.size();
        int m = image[0].size();
        for(int i = 0; i<4 ; i++){
            int newrow = sr[i] + row;
            int newcol = sc[i] + col ;
            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m &&arr[newrow][newcol]!=color &&image[newrow][newcol] == newcolor){
                dfs(newrow,newcol , image , arr , newcolor , color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int newcolor = image[sr][sc];
        vector<vector<int>>arr = image;
        dfs(sr,sc,image,arr,newcolor,color);
        return arr;
    }
};