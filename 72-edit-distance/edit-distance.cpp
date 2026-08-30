class Solution {
public:
    int f(int i1, int i2, vector<vector<int>>& dp,
          string& word1, string& word2) {

        if (i1 == 0) return i2;
        if (i2 == 0) return i1;

        if (dp[i1][i2] != -1)
            return dp[i1][i2];

        // Characters already match
        if (word1[i1 - 1] == word2[i2 - 1]) {
            return dp[i1][i2] =
                f(i1 - 1, i2 - 1, dp, word1, word2);
        }

        // Insert
        int insert = 1 + f(i1, i2 - 1, dp, word1, word2);

        // Delete
        int deletion = 1 + f(i1 - 1, i2, dp, word1, word2);

        // Replace
        int replace = 1 + f(i1 - 1, i2 - 1, dp, word1, word2);

        return dp[i1][i2] =
            min({insert, deletion, replace});
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return f(n, m, dp, word1, word2);
    }
};
