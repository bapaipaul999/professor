class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(auto i : nums){
            sum +=i;
        }
        int count = 0;
        for(int i = 0 ; i< k ; i++){
            if(sum%k == 0){
                return count;
            }
            sum = sum -1;
            count++;
        }
        return count;
    }
};