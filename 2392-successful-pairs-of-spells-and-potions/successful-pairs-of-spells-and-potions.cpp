class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        vector<int> ans2;

        for(int i = 0; i < spells.size(); i++) {
            int start = 0;
            int end = potions.size() - 1;
            int ans = potions.size();

            while(start <= end) {
                int mid = start + (end - start) / 2;

                if(1LL * potions[mid] * spells[i] >= success) {
                    ans = mid;
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }

            ans2.push_back(potions.size() - ans);
        }

        return ans2;
    }
};