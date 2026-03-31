class Solution {
public:
    int funtion(vector<int>& nums,int k){
        if(k<0){
            return 0;
        }
        int left = 0;
        int right = 0;
        int count = 0;
        int odd = 0;
        while(right < nums.size()){
            if(nums[right]%2 == 1){
                odd++;
            }
            while(odd>k){
                if(nums[left]%2 == 1){
                    odd--;
                }
                left++;
            }
            count = count + right - left +1;
            right++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int x = funtion(nums,k) - funtion(nums,k-1);
        return x;
            
        
    }
};