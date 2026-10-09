class Solution {
public:
    set<vector<int>>s1;
    void permutations(vector<int>& nums, int count) {
        if (count == nums.size()) {
            s1.insert(nums);
            return;
        }
        for (int i = count; i < nums.size(); i++) {
            swap(nums[i], nums[count]);
            permutations(nums, count + 1);
            swap(nums[i], nums[count]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permutations(nums, 0);
        for(auto ch : s1){
            ans.push_back(ch);
        }
        return ans;
    }
};