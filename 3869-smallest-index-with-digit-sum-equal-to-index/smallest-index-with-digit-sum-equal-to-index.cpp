class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int ans= -1;
        for(int i = 0 ; i<nums.size(); i++){
            int x = 0;
            int a = nums[i];
            while(a>0){
                x = x+a%10;
                a = a/10;
            }
            if(i == x){
                ans = i;
                break;
            }
        }
        return ans;
    }
};