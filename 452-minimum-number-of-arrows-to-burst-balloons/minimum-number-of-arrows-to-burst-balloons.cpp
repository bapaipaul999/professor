class Solution {
public:
    static bool comparasion(vector<int>first , vector<int>second){
        return first[1]<second[1];
    }
    int findMinArrowShots(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin() , intervals.end() , comparasion);
        long long end = LLONG_MIN;
        int count = 0;
        for(int i = 0 ; i<intervals.size() ; i++){
            if(intervals[i][0]>end){
                count++;
                end = intervals[i][1];
            }
        }
        return count;
    }
};