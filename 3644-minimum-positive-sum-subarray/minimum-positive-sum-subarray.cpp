class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        vector<int>prefix;
        prefix.push_back(0);
        for(int i = 0 ; i<nums.size() ; i++){
            int x = nums[i] + prefix[i];
            prefix.push_back(x);
        }
        for(int i = 0 ; i<nums.size() ; i++){
            for(int j = i ; j<nums.size() ; j++){
                int x = prefix[j+1] - prefix[i] ; 
                if(j-i+1 >= l && j-i+1<=r && x>0){

                    ans = min(ans , x);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};