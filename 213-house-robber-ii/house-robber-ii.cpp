class Solution {
public:
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int prev= nums[0];
        int prev2 = 0;
        for(int i = 1 ; i<nums.size()-1 ; i++){
            int take = nums[i] + prev2 ;
            
            int notTake = prev;
            int curr= max(take , notTake);
            prev2 = prev;
            prev = curr;
            


        }

        int prev3 = nums[1];
        int prev4 = 0;
        for(int i = 2 ; i<nums.size(); i++){
            int take = nums[i] + prev4 ;
            
            int notTake = prev3;
            int curr= max(take , notTake);
            prev4 = prev3;
            prev3 = curr;
            


        }

        return max(prev , prev3);
    }
};