class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int ans = 1;
        int greater_count = 1;
        int smaller_count =1;
        for(int i = 1 ; i<nums.size(); i++){
            if(nums[i]>nums[i-1]){
                greater_count++;
                
            }
            else{
                ans = max(ans , greater_count);
                greater_count = 1;
            }
            if(nums[i]<nums[i-1]){
                smaller_count++;
                
            }
            else{
                ans = max(ans , smaller_count);
                smaller_count = 1;
            }
            
            
        }
        ans = max(ans , greater_count);
        ans = max(ans , smaller_count);
        return ans;


    }
};