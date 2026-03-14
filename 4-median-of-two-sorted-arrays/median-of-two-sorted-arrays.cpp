class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int count1 = 0;
        int count2 = 0;
        vector<double>ans;
        for(int i = 0; i < n+m ; i++){
            if(count1>=n){
                ans.push_back(nums2[count2]);
                count2++;
            }
            else if(count2 >= m){
                ans.push_back(nums1[count1]);
                count1++;
            }
            else if(nums1[count1]>nums2[count2]){
                ans.push_back(nums2[count2]);
                count2++;
            }
            else{
                ans.push_back(nums1[count1]);
                count1++;
            }

        }
        int mid = (n+m)/2;
        if((n+m)%2==0){
            return (ans[mid-1]+ans[mid])/2.0;
        }
        else{
            return ans[mid];
        }
    }
};