class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int i = start + (end -start)/2;

        
        while(start < end){
            if(i%2==0 && nums[i]!=nums[i+1]){
                end = i;
            }
            else if(i%2==0 && nums[i]==nums[i+1]){
                start =i+1;
            }
            else if(i%2==1 && nums[i]==nums[i-1]){
                start =i+1;
            }
            else if(i%2==1 && nums[i]!=nums[i-1]){
                end = i;
            }
            i = start + (end -start)/2;

        }
        return nums[start];
    }
};