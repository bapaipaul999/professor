class Solution {
public:
    int minOperations(vector<int>& nums) {
        int j = 0;
        int opp = 0;
        for (int i = 2; i < nums.size(); i++) {
            int k = j;
            if (nums[k] == 0) {
                opp++;
                while (k <= i) {
                    if(nums[k]){
                        nums[k]=0;
                    }
                    else{
                        nums[k] = 1;
                    }
                    k++;
                }
                
            }
            j++;
        }
        int sum = 0;
        for(int i = 0 ; i<nums.size(); i++){
            sum+=nums[i];
        }

        if(sum == nums.size()){
            return opp;
        }
        return -1;
    }
};