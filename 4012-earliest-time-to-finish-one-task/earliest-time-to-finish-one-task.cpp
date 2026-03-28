class Solution {
public:
    int earliestTime(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        int sum = INT_MAX;
        for(int i =0; i<n ;i++){
            int count =0;
            for(int j = 0; j<m ; j++){
                count = count +nums[i][j];
            }
            sum = min(sum,count);
        }
        return sum;
    }
};