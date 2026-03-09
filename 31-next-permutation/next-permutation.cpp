class Solution {
public:
    
    void nextPermutation(vector<int>& nums) {
        int minindex = -1;
        int n = nums.size();
        for(int i = n-2 ; i>=0 ; i--){
            if(nums[i] < nums[i+1]){
                minindex = i;
                break;

            }
        }
        if(minindex == -1){
            reverse(nums.begin() , nums.end());
            return;
        }
        for(int i = n-1 ; i>minindex ; i--){
            if(nums[i]>nums[minindex]){
                swap(nums[i],nums[minindex]);
                break;
            }
        }
        reverse(nums.begin()+minindex+1 , nums.end());
    }
};