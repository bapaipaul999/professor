class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>check;
        int sum = 0;
        int count = 0;
        check[0] = 1;

        for(int i = 0; i<nums.size() ; i++){
            
            sum += nums[i];
            int x = sum -k;
           
            count += check[x];
            
            check[sum]++;
            

            
            
        }
        return count;
    }
};