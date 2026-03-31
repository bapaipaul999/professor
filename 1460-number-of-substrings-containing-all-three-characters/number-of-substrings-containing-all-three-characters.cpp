class Solution {
public:
    int funtion(string nums,int k){
        
        int left = 0;
        int right = 0;
        int count = 0;
        int special= 0;
        map<char,int>check;
        while(right < nums.size()){
            check[nums[right]]++;
            if(check[nums[right]] == 1){
                special++;
            }
            while(special>k){
                if(check[nums[left]] == 1){
                    special--;
                }
                check[nums[left]]--;
                left++;
            }
            count = count + right - left +1;
            right++;
        }
        return count;
    }
    int numberOfSubstrings(string nums) {
        return funtion(nums,3) - funtion(nums,2);
    }
};