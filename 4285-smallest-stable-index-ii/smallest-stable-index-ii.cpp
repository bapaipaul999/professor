class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>prefix;
        vector<int>sufix(nums.size());
        int maxi = 0;
        int mini = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
           maxi = max(maxi , nums[i]);
           prefix.push_back(maxi);
        }
        for (int i = nums.size()-1; i >= 0 ; i--) {
           mini = min(mini , nums[i]);
           sufix[i] = mini;
        }
        int ans = INT_MAX;
        for(int i = 0 ; i<nums.size() ; i++){
            int x = prefix[i]-sufix[i];
            if(x<=k){
                ans = min(ans , i);
            }
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};