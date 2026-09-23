class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size();
        int m = secondList.size();
        int i = 0 ;
        int j = 0;
        vector<vector<int>>ans;
        while(i<n && j<m){
            int first = max(firstList[i][0] , secondList[j][0]);
            int second = min(firstList[i][1] , secondList[j][1]);
            if(first<=second){
                ans.push_back({first , second});
            }
            if(firstList[i][1]>secondList[j][1]){
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};