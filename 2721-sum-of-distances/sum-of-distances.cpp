class Solution {
public:
    vector<long long> distance(vector<int>& nums) {

        unordered_map<int, vector<int>> mp;

        for(int i=0;i<nums.size();i++)
            mp[nums[i]].push_back(i);

        vector<long long> ans(nums.size());

        for(auto &it : mp){

            vector<int> &v = it.second;
            int m = v.size();

            vector<long long> pre(m+1,0);

            for(int i=0;i<m;i++)
                pre[i+1] = pre[i] + v[i];

            for(int i=0;i<m;i++){

                long long left =
                    1LL*v[i]*i - pre[i];

                long long right =
                    (pre[m]-pre[i+1])
                    - 1LL*v[i]*(m-i-1);

                ans[v[i]] = left + right;
            }
        }

        return ans;
    }
};