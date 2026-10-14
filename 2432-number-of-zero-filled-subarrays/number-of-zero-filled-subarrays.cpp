class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        vector<int>s1;
        int count = 0;
       
        int j = 0;
        while(j<nums.size()){
            if(nums[j]==0){
                
                count++;
            }
            
            else if(nums[j]!=0 && count !=0){
                s1.push_back(count);
                count = 0;

            }
            j++;
        }
        if(count != 0){
            s1.push_back(count);
        }
        long long ans = 0;
        for( auto it : s1){
            ans += (1ll)*it*(it+1)/2;
        }
        return ans;
    }
};