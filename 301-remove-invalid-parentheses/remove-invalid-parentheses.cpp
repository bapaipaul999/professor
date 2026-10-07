class Solution {
public:
    void f(int idx, int count, string &temp, string &s,
           unordered_set<string>& st, int& maxi) {

        if (count < 0) {
            return;
        }

        if (idx == s.size()) {
            if (count == 0) {

                if ((int)temp.size() > maxi) {
                    maxi = temp.size();
                    st.clear();
                    st.insert(temp);
                }
                else if ((int)temp.size() == maxi) {
                    st.insert(temp);
                }
            }
            return;
        }

        if (s[idx] == '(') {

            // Remove '('
            f(idx + 1, count, temp, s, st, maxi);

            // Keep '('
            temp.push_back(s[idx]);
            f(idx + 1, count + 1, temp , s, st, maxi);
            temp.pop_back();
        }
        else if (s[idx] == ')') {

            // Remove ')'
            f(idx + 1, count, temp, s, st, maxi);

            // Keep ')'
            temp.push_back(s[idx]);
            f(idx + 1, count - 1, temp, s, st, maxi);
            temp.pop_back();
        }
        else {

            // Normal character
            temp.push_back(s[idx]);
            f(idx + 1, count, temp, s, st, maxi);
            temp.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        unordered_set<string> st;
        int maxi = 0;
        string temp = "";
        f(0, 0, temp, s, st, maxi);

        vector<string> ans;

        for (auto &x : st) {
            ans.push_back(x);
        }

        return ans;
    }
};