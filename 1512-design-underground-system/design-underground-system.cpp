class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> mpp; // id -> {startStation,time}
    unordered_map<string, pair<int, int>> countSum; // (st+end)station -> {count, timeSum}
    
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        mpp[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [startStation, t1] = mpp[id];
        mpp.erase(id);
        string key = startStation + "#" + stationName;
        countSum[key] = {countSum[key].first+1, countSum[key].second + (t-t1)};
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation+ "#" + endStation;

        double count = countSum[key].first;
        double sum  = countSum[key].second;
        // cout << count << " " << sum << endl;
        return sum / count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */