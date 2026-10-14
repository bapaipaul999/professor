class Solution {
public:
    string ans = "";

    bool check(string &s, string &temp, int k) {
        int j = 0;
        int count = 0;

        for (char c : s) {
            if (c == temp[j]) {
                j++;

                if (j == temp.size()) {
                    j = 0;
                    count++;
                    if (count == k) return true;
                }
            }
        }

        return false;
    }

    void f(string &s, string &temp, vector<int>& freq, int k) {
        if (temp.size() > ans.size() ||
            (temp.size() == ans.size() && temp > ans)) {
            ans = temp;
        }

        for (int i = 25; i >= 0; i--) {
            if (freq[i] >= k) {
                char c = 'a' + i;
                temp.push_back(c);

                if (check(s, temp, k)) {
                    f(s, temp, freq, k);
                }

                temp.pop_back();
            }
        }
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string temp = "";
        f(s, temp, freq, k);

        return ans;
    }
};