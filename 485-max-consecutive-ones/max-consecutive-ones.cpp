class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int j = 0;
        int count = 0;
        for(int i = 0 ; i< nums.size() ; i++){
            if(nums[i] == 1){
                j++;
            }
            else {
                if(count<j){
                    count = j;

                }
                j = 0;

            }
        }
        if(count<j){
            count = j;

        }
        return count;
    }
};