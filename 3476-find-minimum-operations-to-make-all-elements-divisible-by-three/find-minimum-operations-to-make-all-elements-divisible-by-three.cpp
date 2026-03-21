class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        for(int i = 0 ; i< nums.size() ; i++){
            if(nums[i]%3 == 0){
                continue;
            }
            else{
                int x = nums[i] %3;
                int y = nums[i]/3;
                count += min(nums[i]-y*3,(y+1)*3 - nums[i]);
            }
        }
        return count;
    }
};