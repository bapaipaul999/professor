class Solution {
public:
    bool check(vector<int>& nums) {
        int n  = nums.size();
        
        vector<int>nums1(n);
        for(int k = 0 ; k < n ; k ++){
            for(int i = 0 ; i < n ;i++){
                nums1[(i+k)%n] = nums[i];
            }
            int d = 0;
            for(int j = 0 ; j< n-1 ; j++){
                if(nums1[j]>nums1[j+1]){
                    d=1;
                    break;
                }
            }
            if(d == 0){
                return true;
            }
        }
        
        return false;

    }
};