class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> check;

        for (char ch : s) {
            check[ch]++;
        }

        string st = "";

        for (char ch : s) {
            check[ch]--;

            // already in stack
            if (st.find(ch) != string::npos) {
                continue;
            }

            while (!st.empty() && st.back() > ch && check[st.back()] > 0) {
                st.pop_back();
            }

            st.push_back(ch);
        }

        return st;
    }
};