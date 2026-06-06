class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        deque<int>dq;
        for(int i= 0 ; i<piles.size() ; i++){
            dq.push_back(piles[i]);
        }
        int sum = 0 ;
        while(!dq.empty()){
            dq.pop_back();
            sum = sum + dq.back();
            dq.pop_back();
            dq.pop_front();
        }
        return sum;
    }
};