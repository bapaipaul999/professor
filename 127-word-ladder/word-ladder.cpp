class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        map<string, int> mp;

        for (auto it : wordList) {
            mp[it] = 1;
        }

        queue<pair<string, int>> q1;
        q1.push({beginWord, 1});

        mp.erase(beginWord);

        while (!q1.empty()) {

            string word = q1.front().first;
            int count = q1.front().second;
            q1.pop();

            if (word == endWord) {
                return count;
            }

            for (int i = 0; i < word.size(); i++) {

                string temp = word;

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    temp[i] = ch;

                    if (mp.find(temp) != mp.end()) {

                        q1.push({temp, count + 1});
                        mp.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};