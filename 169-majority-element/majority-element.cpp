class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>count;
        for(int i = 0 ; i< nums.size();i++){
            count[nums[i]]++;
        }
        int ans = 0;
        int count1 = 0;
        for(auto it : count){
            if(it.second>count1){
                ans = it.first;
                count1 = it.second;
            }
        }
        return ans;
    }
};