class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>check;
        vector<int>ans;
        for(int i = 0 ; i<nums.size() ; i++){
            int x = target - nums[i];
            if(check.find(x)!=check.end()){
                ans.push_back(check[x]);
                ans.push_back(i);
                break;
            }
            check[nums[i]] = i;
        }
        return ans;
    }
};