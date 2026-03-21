class Solution {
public:
    char repeatedCharacter(string s) {
        map<char,int> check;

        for (auto ch : s) {
            check[ch]++;
            if (check[ch] > 1) {
                return ch;  
            }
        }

        return ' ';
    }
};