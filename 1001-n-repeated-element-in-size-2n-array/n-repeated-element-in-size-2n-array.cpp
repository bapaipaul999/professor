class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int,int>mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int x = 0;
        for(auto i : mp){
            if(i.second == nums.size()/2){
                x = i.first;
            }
        }
        return x;
    }
};