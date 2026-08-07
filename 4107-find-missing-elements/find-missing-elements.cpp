class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int x = *min_element(nums.begin(),nums.end());
        int y = *max_element(nums.begin(),nums.end());
        vector<int>ans;
        set<int>s1;
        for(int i= 0 ; i<nums.size() ; i++){
            s1.insert(nums[i]);
        }
        for(int i = x ; i<=y ;i++){
            if(s1.find(i)==s1.end()){
                ans.push_back(i);
            }
        }
        return ans;

    }
};