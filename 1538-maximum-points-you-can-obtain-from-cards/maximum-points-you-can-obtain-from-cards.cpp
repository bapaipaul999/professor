class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size()-1;
        int lsum = 0;
        int rsum = 0;
        int total = 0;
        int count = 0;
        while(count<k){
            lsum +=nums[l];
            l++;
            count++;
        }
        l--;
        total = lsum;
        count = 0;
        while(lsum>0 && count<k){
            lsum = lsum - nums[l];
            rsum = rsum + nums[r];
            r--;
            l--;
            count++;
            int x = lsum+rsum;
            total = max(x,total);
        }
        return total;
    }
};