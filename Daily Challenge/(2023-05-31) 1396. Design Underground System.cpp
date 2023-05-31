class UndergroundSystem {
    map<int, pair<string, int>> cin;
    map<string, map<string, vector<double>>> avg;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        cin[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string cinstation = cin[id].first;
        int cintime = cin[id].second;
        if(avg[cinstation][stationName].size() == 0) {
            avg[cinstation][stationName] = {(double)(t - cintime), 1};
        }
        else {
            avg[cinstation][stationName][0] += t - cintime;
            ++avg[cinstation][stationName][1];
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double)(avg[startStation][endStation][0])/(double)(avg[startStation][endStation][1]);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */