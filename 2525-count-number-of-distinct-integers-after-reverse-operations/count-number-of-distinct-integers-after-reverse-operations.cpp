class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i<n ; i++){
            int x = nums[i];
            int sum = 0;
            while(x>0){
                int y = x%10;
                sum = sum*10 + y;
                x = x/10;
            }
            nums.push_back(sum);
        }
        set<int>st;
        for(int i = 0 ; i<nums.size() ; i++){
            st.insert(nums[i]);

        }
        int count =st.size();
        
        return count;
    }
};