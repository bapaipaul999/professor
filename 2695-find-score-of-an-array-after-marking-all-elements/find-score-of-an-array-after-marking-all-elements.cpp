class Solution {
public:
    long long findScore(vector<int>& nums) {

        set<pair<int, int>> s;

        for (int i = 0; i < nums.size(); i++) {
            s.insert({nums[i], i});
        }

        long long ans = 0;

        while (!s.empty()) {

            auto it = s.begin();

            int value = it->first;
            int idx = it->second;

            ans += value;

            // erase current element
            s.erase(it);

            // erase left neighbour
            if (idx - 1 >= 0) {
                s.erase({nums[idx - 1], idx - 1});
            }

            // erase right neighbour
            if (idx + 1 < nums.size()) {
                s.erase({nums[idx + 1], idx + 1});
            }
        }

        return ans;
    }
};