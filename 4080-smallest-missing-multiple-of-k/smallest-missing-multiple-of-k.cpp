class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int x = *max_element(nums.begin() , nums.end());
        int y = x/k + 1;
        set<int>s1;
        for(int i = 0 ; i<nums.size() ; i++){
            s1.insert(nums[i]);
        }
        int ans = 0;
        for(int i = 1 ; i <= y ; i++){
            if(s1.find(i*k)==s1.end()){
                ans = i*k;
                break;
            }
        }
        return ans;
    }
};