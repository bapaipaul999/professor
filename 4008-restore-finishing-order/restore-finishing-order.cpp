class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        set<int>check;
        vector<int>ans;
        for(auto i: friends){
            check.insert(i);
        }
        for(auto i: order){
            if(check.find(i)!=check.end()){
                ans.push_back(i);
            }

        }
        return ans;
    }
};