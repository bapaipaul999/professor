class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<vector<int>> temp;

        for(int i = 0; i < difficulty.size(); i++) {
            temp.push_back({difficulty[i], profit[i]});
        }

        sort(temp.begin(), temp.end());

        // Store maximum profit possible up to each difficulty
        int maxProfit = 0;

        for(int i = 0; i < temp.size(); i++) {
            maxProfit = max(maxProfit, temp[i][1]);
            temp[i][1] = maxProfit;
        }

        int ans = 0;

        for(int i = 0; i < worker.size(); i++) {

            int l = 0;
            int r = temp.size() - 1;
            int idx = -1;

            while(l <= r) {
                int mid = l + (r - l) / 2;

                if(temp[mid][0] <= worker[i]) {
                    idx = mid;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }

            if(idx != -1) {
                ans += temp[idx][1];
            }
        }

        return ans;
    }
};