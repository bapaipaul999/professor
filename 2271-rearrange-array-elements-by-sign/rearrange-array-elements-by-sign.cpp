class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        if(nums.size()== 0){
            return nums;
        }
        vector<int>possitives;
        vector<int>negetives;
        for(auto it:nums){
            if(it<0){
                negetives.push_back(it);
                continue;
            }
            possitives.push_back(it);
        }
        int i = 0;
        while(i<nums.size()){
            nums[i] = possitives[i/2];
            nums[i+1]=negetives[i/2];
            i+=2;
        }
        return nums;



    }
};