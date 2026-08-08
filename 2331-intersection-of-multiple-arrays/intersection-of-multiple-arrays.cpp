class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int>mp;
        vector<int>ans;
        for(int i = 0 ; i<nums.size() ; i++){
            for(int j = 0 ; j<nums[i].size(); j++){
                mp[nums[i][j]]++;

            }
        }
        for(auto it : mp){
            if(it.second == nums.size()){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};