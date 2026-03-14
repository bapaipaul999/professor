class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> check;
        int count = 0;
        int left = 0;

        for(int right = 0; right < s.size(); right++){

            while(check.count(s[right])){
                check.erase(s[left]);
                left++;
            }

            check.insert(s[right]);
            count = max(count, right - left + 1);
        }

        return count;
    }
};