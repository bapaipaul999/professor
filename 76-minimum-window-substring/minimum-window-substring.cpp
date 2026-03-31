class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        map<int,int>need;
        for (char ch : t) need[ch]++;

        int required = t.size();   // total chars still needed
        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {
            // include current char in window
            if (need[s[right]] > 0) {
                required--;
            }
            need[s[right]]--;

            // if window is valid, shrink it
            while (required == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                need[s[left]]++;
                if (need[s[left]] > 0) {
                    required++;
                }
                left++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};