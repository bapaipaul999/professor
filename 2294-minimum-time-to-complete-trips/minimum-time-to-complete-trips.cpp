class Solution {
public:
    long long find(vector<int>& time, long long mid) {
        long long trips = 0;

        for (int t : time) {
            trips += mid / t;
        }

        return trips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {

        long long start = 1;
        long long end = 1LL * (*min_element(time.begin(), time.end())) * totalTrips;

        long long ans = end;

        while (start <= end) {

            long long mid = start + (end - start) / 2;

            long long trips = find(time, mid);

            if (trips >= totalTrips) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};