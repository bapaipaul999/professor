class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        unordered_map<int, vector<int>> mp;
        int maxKey = 0;

        
        for(int i = nums.size() - 1; i >= 0; i--){
            for(int j = 0; j < nums[i].size(); j++){
                mp[i + j].push_back(nums[i][j]);
                maxKey = max(maxKey, i + j);
            }
        }

        vector<int> ans;

        for(int k = 0; k <= maxKey; k++){
            for(int val : mp[k]){
                ans.push_back(val);
            }
        }

        return ans;
    }
};
