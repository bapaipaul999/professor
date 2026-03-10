class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i = 0 ; i<nums.size() ; i++){
            mp[nums[i]]++;
        }
        int x = nums.size()/3;
        for(auto it : mp){
            if(it.second>x){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};