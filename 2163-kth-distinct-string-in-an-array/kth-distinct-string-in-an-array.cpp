class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {

        map<string, int> s1;

        for (string s : arr) {
            s1[s]++;
        }

        for (string s : arr) {

            if (s1[s] == 1) {
                k--;

                if (k == 0)
                    return s;
            }
        }

        return "";
    }
};