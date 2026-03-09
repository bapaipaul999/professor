class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum  = 0;
        int max_sum = INT_MIN;
        for(auto it : nums){
            current_sum += it;
            max_sum = max(max_sum,current_sum);
            if(current_sum<0){
                current_sum = 0;
            }
        }
        return max_sum;
    }        
};