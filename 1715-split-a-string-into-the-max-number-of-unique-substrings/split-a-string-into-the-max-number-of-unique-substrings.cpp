class Solution {
public:
    int ans = 0;

    void f(int idx, string& s, unordered_set<string>& st) {

        if (idx == s.size()) {
            ans = max(ans, (int)st.size());
            return;
        }

        string temp = "";

        for (int i = idx; i < s.size(); i++) {

            temp += s[i];

            if (st.find(temp) == st.end()) {

                st.insert(temp);

                f(i + 1, s, st);

                st.erase(temp);
            }
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> st;

        f(0, s, st);

        return ans;
    }
};