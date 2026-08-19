class UndergroundSystem {
public:

    // id -> {stationName, checkInTime}
    unordered_map<int, pair<string, int>> check;

    // route -> {totalTime, numberOfTrips}
    unordered_map<string, pair<int, int>> travel;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        check[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation = check[id].first;
        int startTime = check[id].second;

        string route = startStation + "#" + stationName;

        int time = t - startTime;

        travel[route].first += time;
        travel[route].second++;

        check.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "#" + endStation;

        return (double)travel[route].first / travel[route].second;
    }
};
/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */