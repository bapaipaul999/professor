class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        map<char, int> check;
        int max_freq = 0;
        int ans = 0;

        while (right < s.size()) {
            check[s[right]]++;
            max_freq = max(max_freq, check[s[right]]);

            while ((right - left + 1) - max_freq > k) {
                check[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};