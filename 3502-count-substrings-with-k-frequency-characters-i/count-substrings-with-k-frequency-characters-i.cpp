class Solution {
public:
    long long numberOfSubstrings(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0;
        long long ans = 0;
        int n = s.size();

        for (int right = 0; right < n; right++) {
            freq[s[right] - 'a']++;

            while (freq[s[right] - 'a'] >= k) {
                ans += (n - right);
                freq[s[left] - 'a']--;
                left++;
            }
        }

        return ans;
    }
};