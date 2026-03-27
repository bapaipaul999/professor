class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n = nums.size();
        if (n == k) {
            return "0";
        }

        stack<char> s1;

        for (int i = 0; i < n; i++) {
            while (!s1.empty() && s1.top() > nums[i] && k > 0) {
                s1.pop();
                k--;
            }
            s1.push(nums[i]);
        }

        while (k > 0) {
            s1.pop();
            k--;
        }

        string ans = "";

        // build reversed answer
        while (!s1.empty()) {
            ans += s1.top();
            s1.pop();
        }

        reverse(ans.begin(), ans.end());

        // remove leading zeros
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i);

        if (ans == "") return "0";

        return ans;
    }
};