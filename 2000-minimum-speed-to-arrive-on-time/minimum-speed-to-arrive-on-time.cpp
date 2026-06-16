class Solution {
public:
    double find(vector<int>& dist, int speed) {
        double time = 0;

        for(int i = 0; i < dist.size() - 1; i++) {
            time += ceil((double)dist[i] / speed);
        }

        time += (double)dist.back() / speed;

        return time;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {

        int start = 1;
        int end = 1e7;
        int ans = -1;

        while(start <= end) {

            int mid = start + (end - start) / 2;

            double time = find(dist, mid);

            if(time <= hour) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return ans;
    }
};