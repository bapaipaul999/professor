class Solution {
public:
    int sz;
    unordered_map<int, int> mp;

    Solution(int n, vector<int>& blacklist) {
        sz = n - blacklist.size();

        unordered_set<int> blocked(blacklist.begin(), blacklist.end());

        int last = n - 1;

        for (int b : blacklist) {
            if (b < sz) {
                while (blocked.count(last)) {
                    last--;
                }

                mp[b] = last;
                last--;
            }
        }
    }

    int pick() {
        int x = rand() % sz;
        if (mp.count(x)) {
            return mp[x];
        }
        return x;
    }
};