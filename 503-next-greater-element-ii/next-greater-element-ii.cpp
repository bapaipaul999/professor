class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        

        vector<int> ans(nums.size());
        stack<int> s1;
        stack<int> s2;
        for(int i = nums.size() - 1; i >= 0; i--){
            s2.push(nums[i]);
        }

        for(int i = nums.size() - 1; i >= 0; i--){
            while(!s1.empty() && nums[i] >= s1.top()){
                s1.pop();
            }

            if(s1.empty()){
                while(!s2.empty() && nums[i] >= s2.top()){
                    s2.pop();
                }
                if(s2.empty()){
                    ans[i] = -1;
                }
                else{
                    ans[i] = s2.top();
                }    

            }
            else {
                ans[i] = s1.top();
            }

            s1.push(nums[i]);
        }

        
        return ans;
    }
};