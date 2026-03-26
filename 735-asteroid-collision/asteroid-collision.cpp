class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        
        stack<int> s1;
        
        for (int i = 0; i < nums.size(); i++) {
            
            if (nums[i] > 0) {
                s1.push(nums[i]);
                continue;
            }
            
            int x = -nums[i];

            
            while (!s1.empty() && s1.top() > 0 && x > s1.top()) {
                s1.pop();
            }

    
            if (!s1.empty() && s1.top() > 0 && x == s1.top()) {
                s1.pop();
                continue;
            }

           
            if (s1.empty() || s1.top() < 0) {
                s1.push(nums[i]);
            }


        }

        int n = s1.size();
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            ans[i] = s1.top();
            s1.pop();
        }

        return ans;
    }
};