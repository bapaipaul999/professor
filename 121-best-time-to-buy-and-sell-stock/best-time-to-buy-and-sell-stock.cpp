class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int j = 0;
        int count = 0;
        while(j<prices.size()){
            int k = prices[j] - prices[i];
            if(k < 0){
                i = j;
                j++;
                continue;
            }
            count = max(count , k);
            j++;
        }
        return count;
    }
};