class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp1;
        map<int,int>mp2;
        vector<int>ans;
        for(int i = 0 ; i< nums1.size() ; i++){
            mp1[nums1[i]]++;
        }
        for(int i = 0 ; i< nums2.size() ; i++){
            if(mp2[nums2[i]]<mp1[nums2[i]]){
                ans.push_back(nums2[i]);
            }
            mp2[nums2[i]]++;

        }
        return ans;

    }
};