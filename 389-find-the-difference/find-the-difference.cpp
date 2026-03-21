class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;

        for (auto ch : s) {
            mp[ch]++;
        }

        for (auto ch : t) {
            if (mp[ch] == 0) {
                return ch;
            }
            mp[ch]--;
        }

        return ' '; 
    }
};