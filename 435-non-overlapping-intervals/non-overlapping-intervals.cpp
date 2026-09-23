class Solution {
public:
    static bool comparasion(vector<int>first , vector<int>second){
        return first[1]<second[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin() , intervals.end() , comparasion);
        int end = INT_MIN;
        int count = 0;
        for(int i = 0 ; i<intervals.size() ; i++){
            if(intervals[i][0]>=end){
                count++;
                end = intervals[i][1];
            }
        }
        return n-count;
    }
};