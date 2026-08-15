class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;
        int maxi = 0;
        map<char, int> mp;
        int left = 0;

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            maxi++;

            while (mp[s[i]] > 2) {
                mp[s[left]]--;
                maxi--;
                left++;
            }

            ans = max(ans, maxi);
        }

        return ans;
    }
};