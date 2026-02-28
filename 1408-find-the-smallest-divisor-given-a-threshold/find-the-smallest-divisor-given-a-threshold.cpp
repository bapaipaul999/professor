class Solution {
public:
    
    int computeSum(vector<int>& nums, int divisor) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += (nums[i] + divisor - 1) / divisor;  
        }
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        int ans = end;
        
        while(start <= end) {
            
            int mid = start + (end - start) / 2;
            
            int sum = computeSum(nums, mid);
            
            if(sum <= threshold) {
                ans = mid;
                end = mid - 1;   
            }
            else {
                start = mid + 1; 
            }
        }
        
        return ans;
    }
};