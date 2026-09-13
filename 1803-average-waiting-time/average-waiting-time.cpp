class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int j = customers[0][0];
        double sum = 0;
        for(int i = 0 ; i<n ; i++){
            if(j<customers[i][0]){
                sum+= customers[i][1];
                j = customers[i][0]+customers[i][1];
                continue;
            }
            j = j+ customers[i][1];
            int x = j-customers[i][0];
            sum += x;
        }
        double ans = sum/n;
        return ans;
    }
};