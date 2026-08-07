class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int start = 1;
        int end = grid.size()*grid.size();
        set<int>s1;
        s1.insert(grid[0][0]);
        int missing ;
        int dublicate;
        for(int i = 0 ; i<grid.size();i++){
            for(int j = 0 ; j<grid.size();j++){
                if(i == 0 && j == 0){
                    continue;
                }
                if(s1.find(grid[i][j])!=s1.end()){
                    dublicate = grid[i][j];
                    
                }
                s1.insert(grid[i][j]);
            }
        }
        for(int i = start ; i<=end ; i++){
            if(s1.find(i)==s1.end()){
                missing = i;
                break;
            }
        }
        vector<int>ans;
        ans.push_back(dublicate);
        ans.push_back(missing);
        return ans;
    }
};