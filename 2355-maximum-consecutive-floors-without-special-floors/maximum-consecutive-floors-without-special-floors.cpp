class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());

        int ans = 0;

        // Before first special floor
        ans = max(ans, special[0] - bottom);

        // Between special floors
        for (int i = 1; i < special.size(); i++) {
            ans = max(ans, special[i] - special[i - 1] - 1);
        }

        // After last special floor
        ans = max(ans, top - special.back());

        return ans;
    }
};