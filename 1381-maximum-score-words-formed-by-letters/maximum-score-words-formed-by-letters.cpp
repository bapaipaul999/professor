class Solution {
public:
    int f(int idx, vector<string>& words, vector<int>& values,
          map<char, int>& mp) {

        if(idx == words.size()) {
            return 0;
        }

        // Don't take this word
        int ans = f(idx + 1, words, values, mp);

        // Check whether this word can be formed
        bool possible = true;

        map<char, int> need;

        for(char ch : words[idx]) {
            need[ch]++;

            if(need[ch] > mp[ch]) {
                possible = false;
                break;
            }
        }

        // Take the word
        if(possible) {

            // Remove its letters
            for(char ch : words[idx]) {
                mp[ch]--;
            }

            ans = max(ans,
                      values[idx] + f(idx + 1, words, values, mp));

            // Put letters back
            for(char ch : words[idx]) {
                mp[ch]++;
            }
        }

        return ans;
    }

    int maxScoreWords(vector<string>& words,
                      vector<char>& letters,
                      vector<int>& score) {

        vector<int> values;

        for(int i = 0; i < words.size(); i++) {

            int x = 0;

            for(int j = 0; j < words[i].size(); j++) {
                int y = words[i][j] - 'a';
                x += score[y];
            }

            values.push_back(x);
        }

        map<char, int> mp;

        for(char ch : letters) {
            mp[ch]++;
        }

        return f(0, words, values, mp);
    }
};