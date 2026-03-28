class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        if (k >= n) {
            int maxi = nums[0];
            for (int i = 1; i < n; i++) {
                maxi = max(maxi, nums[i]);
            }
            ans.push_back(maxi);
            return ans;
        }

        deque<int> s1; // store indices
       
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (count < k) {
                while (!s1.empty() && nums[s1.back()] <= nums[i]) {
                    s1.pop_back();
                }
                s1.push_back(i);
                count++;
            } 
            else {
                ans.push_back(nums[s1.front()]);

                // remove out of window index
                if (!s1.empty() && s1.front() <= i - k) {
                    s1.pop_front();
                }

                while (!s1.empty() && nums[s1.back()] <= nums[i]) {
                    s1.pop_back();
                }
                s1.push_back(i);
            }
        }

        ans.push_back(nums[s1.front()]);
        return ans;
    }
};