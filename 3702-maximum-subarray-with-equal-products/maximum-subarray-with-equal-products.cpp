class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 2;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                bool valid = true;

                for(int k = i; k < j; k++) {
                    if(gcd(nums[k], nums[j]) != 1) {
                        valid = false;
                        break;
                    }
                }

                if(valid)
                    ans = max(ans, j - i + 1);
                else
                    break;
            }
        }

        return ans;
    }
};