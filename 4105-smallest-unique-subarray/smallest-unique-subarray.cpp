class Solution {
public:
    using ll = long long;

    const ll M1 = 1000000007;
    const ll M2 = 1000000009;
    const ll B = 137;

    bool check(int len, vector<int>& nums,
               vector<ll>& h1, vector<ll>& h2,
               vector<ll>& p1, vector<ll>& p2) {

        map<pair<ll, ll>, int> cnt;
        int n = nums.size();

        for (int i = 0; i + len <= n; i++) {
            int j = i + len;

            ll x = (h1[j] - h1[i] * p1[len] % M1 + M1) % M1;
            ll y = (h2[j] - h2[i] * p2[len] % M2 + M2) % M2;

            cnt[{x, y}]++;
        }

        for (auto& it : cnt) {
            if (it.second == 1)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<ll> h1(n + 1, 0), h2(n + 1, 0);
        vector<ll> p1(n + 1, 1), p2(n + 1, 1);

        for (int i = 0; i < n; i++) {
            ll val = nums[i] + 1;

            h1[i + 1] = (h1[i] * B + val) % M1;
            h2[i + 1] = (h2[i] * B + val) % M2;

            p1[i + 1] = p1[i] * B % M1;
            p2[i + 1] = p2[i] * B % M2;
        }

        int l = 1, r = n, ans = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(mid, nums, h1, h2, p1, p2)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};