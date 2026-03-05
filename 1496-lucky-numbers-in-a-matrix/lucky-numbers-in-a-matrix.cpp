class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> maxi;
        int start = 0;
        int end = n*m -1;
        while(start <= end){
            int i = start /m ;
            int j = start %m;
            int c = 1;
            for(int r =0 ; r<m ; r++){
                if(matrix[i][j] > matrix[i][r]){
                    c= 0;
                    break;
                }
            }
            if(c==1){
               for(int r =0 ; r<n ; r++){
                    if(matrix[i][j] < matrix[r][j]){
                        c= 0;
                        break;
                    }
                } 
            }
            if(c==1){
                maxi.push_back(matrix[i][j]);
                break;
            }
            i = end /m ;
            j = end %m;
            c = 1;
            for(int r =0 ; r<m ; r++){
                if(matrix[i][j] > matrix[i][r]){
                    c= 0;
                    break;
                }
            }
            if(c==1){
               for(int r =0 ; r<n ; r++){
                    if(matrix[i][j] < matrix[r][j]){
                        c= 0;
                        break;
                    }
                } 
            }
            if(c==1){
                maxi.push_back(matrix[i][j]);
                break;
            }
            start++;
            end--;

        }
        
        return maxi;
    }
};