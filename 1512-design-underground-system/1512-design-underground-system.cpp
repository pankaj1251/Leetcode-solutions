class UndergroundSystem {
private:
    map<pair<string, string>, int>out, count;
    unordered_map<int, pair<string, int>>in;

public:
    UndergroundSystem(){
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        auto it = in[id];
        out[{it.first, stationName}] += t - it.second;
        count[{it.first, stationName}]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        double avg;
        avg = (double)out[{startStation, endStation}] / count[{startStation, endStation}];
        return avg;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */