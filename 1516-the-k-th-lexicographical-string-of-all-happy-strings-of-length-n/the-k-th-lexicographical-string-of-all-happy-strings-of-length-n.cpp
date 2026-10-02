class Solution {
public:
    void f(char prev, int n, string s, vector<string>& ans) {

        if(n == 0) {
            ans.push_back(s);
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++) {

            if(ch == prev)
                continue;

            f(ch, n - 1, s + ch, ans);
        }
    }

    string getHappyString(int n, int k) {

        vector<string> ans;

        f('#', n, "", ans);

        if(k > ans.size())
            return "";

        return ans[k - 1];
    }
};