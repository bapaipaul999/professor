class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        map<int,int>check;
        for(int i = 0; i<nums.size() ; i++){
            check[nums[i]]++;
        }
        for( auto it : check){
            if(it.second == 2){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};