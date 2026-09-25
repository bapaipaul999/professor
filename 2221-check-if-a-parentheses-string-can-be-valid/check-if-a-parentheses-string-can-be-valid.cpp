class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        if (n % 2 != 0) {
            return false;
        }

        int low = 0;
        int high = 0;

        for (int i = 0; i < n; i++) {

            if (locked[i] == '0') {
                // We can choose '(' or ')'
                low--;
                high++;
            }
            else {
                // Fixed character
                if (s[i] == '(') {
                    low++;
                    high++;
                }
                else {
                    low--;
                    high--;
                }
            }

            // We cannot have negative possible opens
            if (high < 0) {
                return false;
            }

            // Minimum cannot be negative
            low = max(low, 0);
        }

        return low == 0;
    }
};