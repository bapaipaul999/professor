class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin() , costs.end());
        int count = 0;

        for(int i = 0 ; i<costs.size() ; i++){
            coins = coins - costs[i];
            if(coins<0){
                return count;
            }
            count++;
        }
        return count;


        
    }
};