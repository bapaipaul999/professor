class Solution {
public:
    int f(vector<int>& freq) {

        int count = 0;

        for(int i = 0; i < 26; i++) {

            if(freq[i] == 0)
                continue;

            // Choose this character
            freq[i]--;

            // The newly formed sequence is one possibility
            count++;

            // Continue making a longer sequence
            count += f(freq);

            // Backtrack
            freq[i]++;
        }

        return count;
    }

    int numTilePossibilities(string tiles) {

        vector<int> freq(26, 0);

        for(char c : tiles) {
            freq[c - 'A']++;
        }

        return f(freq);
    }
};