class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int first = 0;
  
        bool first1 = true;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i]%2 == 1){
                first1 = !first1;
            }
            if((i+1 )% 6 == 0){
                first1 = !first1;
            }
            if(first1){
                first+=nums[i];
            }
            else{
                first-=nums[i];
            }
        }
        return first;
    }
};