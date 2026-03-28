class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        
        stack<int>s1;
        for(int i = n-1 ; i>=0 ; i--){
            while(!s1.empty() && nums[s1.top()]<=nums[i]){
                s1.pop();
            }
            if(s1.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = s1.top();
            }
            s1.push(i);
        }
        vector<int>arr(n);
        for(int i = 0 ; i< n ; i++){
            if(ans[i]==-1){
                arr[i] = 0;
                continue;
            }
            int x = ans[i] - i;
            arr[i] = x;
        }
        return arr;
        
    }
};