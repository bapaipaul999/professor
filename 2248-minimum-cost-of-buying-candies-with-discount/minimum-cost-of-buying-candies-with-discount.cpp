class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin() , cost.rend());
        int sum = 0;
        int count = 1;
        for(int i = 0 ; i<cost.size() ; i++){
            if(count % 3 != 0){
                sum +=cost[i];
            }
            count++;
        }
        return sum;
    }
};