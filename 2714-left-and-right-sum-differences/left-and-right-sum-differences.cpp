class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>left(nums.size());
        vector<int>right(nums.size());
        int count = 0 ; 
        for( int i = 0; i< nums.size() ; i++){
            left[i] = count;
            count +=nums[i];
        }
        count = 0;
        for( int i = nums.size()-1; i>=0; i--){
            right[i] = count;
            count +=nums[i];
        }
        for( int i = 0; i< nums.size() ; i++){
            int x = left[i] - right[i];
            if(x<0){
                x = -x;
            }
            nums[i] = x;
        }
        return nums;

    }
};