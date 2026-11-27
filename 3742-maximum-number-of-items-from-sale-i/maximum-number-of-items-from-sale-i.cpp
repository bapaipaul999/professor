class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int>freeGain(n,0);
        for(int i = 0; i<n ; i++){
            int factorI = items[i][0];
            for(int j = 0; j<n ; j++){
                if(i!=j && items[j][0] % factorI == 0){
                    freeGain[i]++;
                }
            }
        }
        vector<int> dp(budget + 1 ,0);
        for(int i = 0 ; i<n ; i++){
            int price = items[i][1];
            int firstGain = 1+freeGain[i];
            vector<int> newDp = dp;
            for(int b = price ; b<=budget ; b++){
                newDp[b] = max(newDp[b],dp[b-price]+firstGain);
            }
            for(int b = price ; b<=budget ; b++){
                newDp[b] = max(newDp[b] , newDp[b-price] +1);
            }
            dp = newDp;
        }
        return dp[budget];
    }
};