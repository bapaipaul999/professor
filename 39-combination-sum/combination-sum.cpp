class Solution {
public:
    void f(int idx , int sum , int target ,vector<int>temp ,  vector<int>candidates , vector<vector<int>>&ans){
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        if(idx == candidates.size()){
            return;
        }
        if(sum>target){
            return ;
        }
        f(idx+1 , sum , target ,temp , candidates , ans );
        temp.push_back(candidates[idx]);
        f(idx , sum+candidates[idx] , target ,temp , candidates , ans );


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        f(0, 0, target, temp, candidates, ans);

        return ans;
    }
};