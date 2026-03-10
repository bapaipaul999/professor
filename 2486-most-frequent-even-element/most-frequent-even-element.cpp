class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int x  = INT_MIN;
        int count = 0;
        unordered_map<int,int>mp;
        for(int i = 0 ; i< nums.size() ; i++){
            if(nums[i]%2 == 0){
                mp[nums[i]]++;
                count++;
            }
        }
        if(count == 0){
            return -1;
        }
        int ans;
        for(auto it : mp){
            if(it.second > x){
                ans = it.first;
                x = it.second;
                
            }
            else if(it.second == x){
                ans = min(it.first,ans);
            }
        }
        return ans;
    }
};