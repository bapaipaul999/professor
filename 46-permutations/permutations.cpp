class Solution {
public:
    void permutations(vector<int>& nums,int count , vector<vector<int>> &ans){
        if(count== nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = count ; i<nums.size() ; i++){
            swap(nums[i],nums[count]);
            permutations(nums,count+1,ans);
            swap(nums[i] , nums[count]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        permutations(nums,0,ans);
        return ans;
    }
};