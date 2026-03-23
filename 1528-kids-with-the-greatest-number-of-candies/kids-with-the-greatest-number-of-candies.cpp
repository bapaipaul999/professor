class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int x = *max_element(candies.begin(),candies.end());
        
        vector<bool>ans;

        for(auto i : candies){
            int y = extraCandies + i;
            if(y>=x){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};