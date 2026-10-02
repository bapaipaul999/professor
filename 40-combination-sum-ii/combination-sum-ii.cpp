class Solution {
public:
    void f(int idx, int target, vector<int>& temp,
           vector<vector<int>>& ans, vector<int>& candidates) {

        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        for(int i = idx; i < candidates.size(); i++) {

            if(i > idx && candidates[i] == candidates[i - 1])
                continue;

            if(candidates[i] > target)
                break;

            temp.push_back(candidates[i]);

            f(i + 1, target - candidates[i],
              temp, ans, candidates);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        f(0, target, temp, ans, candidates);

        return ans;
    }
};