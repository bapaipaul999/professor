class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        for(int i = 0; i<nums.size() ; i++){
            mp[nums[i]] = i;
        }
        for(int i = 0 ; i<nums.size(); i++){
            int x = target -nums[i];
            if(mp.find(x)!=mp.end()){
                int y = mp[x];
                if(y!=i){
                    return {min(i+1,y+1) , max(i+1,y+1)};
                }
                
            }
        }
        return {-1,-1};
    }
};