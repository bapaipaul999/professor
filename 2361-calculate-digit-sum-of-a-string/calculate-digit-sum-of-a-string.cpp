
class Solution {
public:
    string digitSum(string s, int k) {
        string x = s;

        while (x.size() > k) {
            int sum = 0;
            int count = 0;
            string y = "";

            for (int i = 0; i < x.size(); i++) {
                sum += x[i] - '0';
                count++;

                if (count == k) {
                    y += to_string(sum);
                    sum = 0;
                    count = 0;
                }
            }

            if (count > 0) {
                y += to_string(sum);
            }

            x = y;
        }

        return x;
    }
};
