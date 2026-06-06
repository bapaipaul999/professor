class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n = score.size();
        int m = score[0].size();
        map<int,int>mp;
        for(int i = 0 ; i< n ;i++){
            mp[score[i][k]] = i;
        }
        vector<vector<int>> temp(n,vector<int>(m,0));
        int count = n-1;
        for(auto it : mp){
            temp[count] = score[it.second];
            count -- ;
        }
        return temp;
    }
};