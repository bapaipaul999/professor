class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int>check;
        int total = 0;

        for(int i =0 ; i<nums.size() ; i++){
            if(check.find(nums[i])!= check.end()){
                total+=check[nums[i]];
            }
            check[nums[i]]++;
        }
        return total;
    }
};