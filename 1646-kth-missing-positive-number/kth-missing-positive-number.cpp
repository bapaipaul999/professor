class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>nums;
        set<int>check;

        int x = *max_element(arr.begin(),arr.end());
        for(int i = 0; i<arr.size();i++){
            check.insert(arr[i]);
        }
        for(int i = 0 ; i<=x+k ; i++){
            if(check.find(i)==check.end()){
                nums.push_back(i);
            }
        }
        return nums[k];

    }
};