class Solution {
public:
    string getHint(string secret, string guess) {
        map<char, int> s1;

        for (char ch : secret) {
            s1[ch]++;
        }

        int bulls = 0;
        int cows = 0;

        // Count bulls
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
                s1[secret[i]]--;
                if (s1[secret[i]] == 0) {
                    s1.erase(secret[i]);
                }
            }
        }

        // Count cows
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] != guess[i] &&
                s1.find(guess[i]) != s1.end()) {

                cows++;
                s1[guess[i]]--;

                if (s1[guess[i]] == 0) {
                    s1.erase(guess[i]);
                }
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};