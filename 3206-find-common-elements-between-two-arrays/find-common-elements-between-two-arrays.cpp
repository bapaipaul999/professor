class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int count1 = 0;
        int count2 = 0;
        set<int> st1(nums1.begin(), nums1.end());
        set<int> st2(nums2.begin(), nums2.end());
        vector<int>ans;
        for(int i = 0 ; i<nums1.size(); i++){
            if(st2.find(nums1[i])!=st2.end()){
                count1++;
            }
        }
        ans.push_back(count1);
        for(int i = 0 ; i<nums2.size(); i++){
            if(st1.find(nums2[i])!=st1.end()){
                count2++;
            }
        }
        ans.push_back(count2);
        return ans;
    }
};