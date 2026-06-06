class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {

        vector<tuple<long long,int,int>> ans;

        for(int i = 0; i < nums.size(); i++) {

            int temp = nums[i];

            if(temp == 0) {
                ans.push_back({mapping[0], i, nums[i]});
                continue;
            }

            long long mapped = 0;
            long long place = 1;

            while(temp > 0) {
                int digit = temp % 10;
                mapped += 1LL * mapping[digit] * place;
                place *= 10;
                temp /= 10;
            }

            ans.push_back({mapped, i, nums[i]});
        }

        sort(ans.begin(), ans.end());

        vector<int> res;

        for(auto &it : ans) {
            res.push_back(get<2>(it));
        }

        return res;
    }
};