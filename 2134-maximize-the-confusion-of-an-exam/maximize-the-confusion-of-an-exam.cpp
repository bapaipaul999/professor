class Solution {
public:
    int maxConsecutiveAnswers(string nums, int k) {
        int ans = 0;
        int max_freq = 0;
        map<char,int>check;
        int left = 0;
        int right = 0;
        while(right<nums.size()){
            check[nums[right]]++;
            max_freq = max(max_freq , check[nums[right]]);
            while(right-left+1 - max_freq > k){
                check[nums[left]]--;
                left++;
            }
            ans = max(ans , right - left +1);
            right++;
        }
        return ans;
    }
};