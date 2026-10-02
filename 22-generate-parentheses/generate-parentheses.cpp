class Solution {
public:
    void f(int n, int k, string s, vector<string>& ans) {

        if(n == 0) {
            if(k == 0)
                ans.push_back(s);
            return;
        }

        // add '('
        if(k < n) {
            f(n, k + 1, s + '(', ans);
        }

        // add ')'
        if(k > 0) {
            f(n - 1, k - 1, s + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        f(n, 0, "", ans);
        return ans;
    }
};