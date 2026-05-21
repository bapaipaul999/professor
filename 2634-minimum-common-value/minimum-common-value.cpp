class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1;
        int mini = INT_MAX;
        for(auto i : nums1){
            s1.insert(i);
        }
        for(int i = 0; i< nums2.size(); i++){
            if(s1.find(nums2[i])!=s1.end()){
                mini = min(mini,nums2[i]);
            }
        }
        if(mini == INT_MAX){
            return -1;
        }
        return mini;
    }
};