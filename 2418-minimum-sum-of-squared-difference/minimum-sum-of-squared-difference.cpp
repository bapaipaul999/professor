
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);
        long long k = 1LL * k1 + k2;
        int mx = 0;
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
            total += diff[i];
        }

        if (k >= total) return 0;

        // Find the smallest level such that
        // reducing all differences to this level costs <= k.
        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long need = 0;

            for (int x : diff) {
                if (x > mid)
                    need += x - mid;
            }

            if (need <= k)
                high = mid;
            else
                low = mid + 1;
        }

        int level = low;
        long long need = 0;

        for (int x : diff) {
            if (x > level)
                need += x - level;
        }

        long long rem = k - need;
        long long ans = 0;

        for (int x : diff) {
            long long val = min(x, level);

            // Use leftover operations to reduce some values by 1.
            if (x >= level && val > 0 && rem > 0) {
                val--;
                rem--;
            }

            ans += val * val;
        }

        return ans;
    }
};
