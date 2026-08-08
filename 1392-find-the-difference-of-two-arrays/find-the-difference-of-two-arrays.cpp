class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1(nums1.begin() , nums1.end());
        set<int>s2(nums2.begin() , nums2.end());
        vector<vector<int>> ans;
        vector<int>temp1;
        vector<int>temp2;
        for(auto it : s1){
            if(s2.find(it)==s2.end()){
                temp1.push_back(it);
            }
        }
        for(auto it : s2){
            if(s1.find(it)==s1.end()){
                temp2.push_back(it);
            }
        }
        ans.push_back(temp1);
        ans.push_back(temp2);
        return ans;
    }
};