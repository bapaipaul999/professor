class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int sum = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            sum+=nums[i];
        }
        int mini = INT_MAX;
        int current = 0;
        for(int i = 0 ; i<sum ; i++){
            current+=nums[i];
        }
        mini = min(mini , sum - current);
        int j = sum;
        for(int i= 1 ; i<nums.size() ; i++){
            if(j>=nums.size()){
                current = current - nums[i-1] + nums[j-nums.size()];
            }
            else{
                current=current - nums[i-1] + nums[j];
            }
            j++;
            mini = min(mini , sum-current);
            
            
        }
        return mini;
    }
};