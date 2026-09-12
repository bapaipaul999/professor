class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        int m = meetings.size();

        sort(meetings.begin(), meetings.end());

        vector<vector<long long>> room(n, vector<long long>(3, 0));

        for (int i = 0; i < m; i++) {

            long long start = meetings[i][0];
            long long end = meetings[i][1];
            long long diff = end - start;

            int idx = -1;

            // Find a free room with smallest index
            for (int j = 0; j < n; j++) {
                if (room[j][1] <= start) {
                    idx = j;
                    break;
                }
            }

            if (idx != -1) {
                // Room is free
                room[idx][1] = end;
                room[idx][2]++;
            }
            else {
                // No room is free
                idx = 0;

                for (int j = 1; j < n; j++) {
                    if (room[j][1] < room[idx][1]) {
                        idx = j;
                    }
                }

                // Delay this meeting
                room[idx][1] += diff;
                room[idx][2]++;
            }
        }

        int ans = 0;

        for (int i = 1; i < n; i++) {
            if (room[i][2] > room[ans][2]) {
                ans = i;
            }
        }

        return ans;
    }
};