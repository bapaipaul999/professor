class Solution {
public:
    void f(int idx, string temp, string &s, vector<string>& ans) {
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }

        if (s[idx] >= '0' && s[idx] <= '9') {
            f(idx + 1, temp + s[idx], s, ans);
        }
        else {
            f(idx + 1, temp + (char)tolower(s[idx]), s, ans);
            f(idx + 1, temp + (char)toupper(s[idx]), s, ans);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        f(0, "", s, ans);
        return ans;
    }
};