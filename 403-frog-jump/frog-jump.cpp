class Solution {
public:
    bool f(int i, int jump,
           vector<vector<int>>& dp,
           map<int, int>& mp,
           vector<int>& stones) {

        // Reached last stone
        if (i == stones.size() - 1) {
            return true;
        }

        if (dp[i][jump] != -1) {
            return dp[i][jump];
        }

        dp[i][jump] = false;

        // Try jump-1, jump, jump+1
        for (int d = -1; d <= 1; d++) {

            int nextJump = jump + d;

            if (nextJump <= 0) {
                continue;
            }

            int nextStone = stones[i] + nextJump;

            // Check whether next stone exists
            if (mp.find(nextStone) != mp.end()) {

                int nextIndex = mp[nextStone];

                if (f(nextIndex, nextJump,
                      dp, mp, stones)) {

                    return dp[i][jump] = true;
                }
            }
        }

        return dp[i][jump] = false;
    }

    bool canCross(vector<int>& stones) {

        int n = stones.size();
        if(stones[1]-stones[0]!=1){
            return false;
        }

        // stone position -> index
        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }

        // dp[i][jump]
        vector<vector<int>> dp(
            n,
            vector<int>(n + 1, -1)
        );

        // First jump must be 1
        return f(1, 1, dp, mp, stones);
    }
};