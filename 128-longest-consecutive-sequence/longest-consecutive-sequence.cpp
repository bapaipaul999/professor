class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        set<int>check;
        for(int i = 0 ; i< nums.size() ; i++){
            check.insert(nums[i]);

        }
        int count = 0;
        int max_count = 0;
        int prev = INT_MIN;
        for(auto it :check){
            if(it-1 == prev){
                count++;
                prev = it;
            }
            else if(it != prev){
                count = 1;
                prev = it;
            }
            max_count = max(max_count , count);
        }
        return max_count;
    }
};