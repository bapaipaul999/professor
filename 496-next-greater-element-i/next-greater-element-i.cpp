class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        map<int,int> check;
        for(int i = 0; i < nums2.size(); i++){
            check[nums2[i]] = i;
        }

        vector<int> ans(nums2.size());
        stack<int> s1;

        for(int i = nums2.size() - 1; i >= 0; i--){
            while(!s1.empty() && nums2[i] >= s1.top()){
                s1.pop();
            }

            if(s1.empty()){
                ans[i] = -1;
            } else {
                ans[i] = s1.top();
            }

            s1.push(nums2[i]);
        }

        for(int i = 0; i < nums1.size(); i++){
            int idx = check[nums1[i]];
            nums1[i] = ans[idx];
        }

        return nums1;
    }
};