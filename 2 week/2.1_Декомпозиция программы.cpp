#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Time{
public:
    Time() 
        : start(steady_clock::now())
    {
    }
    ~Time() {
        auto finish = steady_clock::now();
        auto dur = finish - start;
        cout << duration_cast<milliseconds>(dur).count()
            << " ms" << endl;
    }
private:
    steady_clock::time_point start;
};

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {    
    string command;
    is >> command;
    if (command == "NEW_BUS") {
        q.type = QueryType::NewBus;
        is >> q.bus;
        int count = 0;
        is >> count;
        q.stops.resize(count);
        for (auto& stop : q.stops) {
            is >> stop;
        }
    } 
    else if (command == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    } 
    else if (command == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    } 
    else if (command == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    }
    return is;
}

struct BusesForStopResponse {
    vector<string> buses_for_stop_at_stop;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    if (r.buses_for_stop_at_stop.empty()) {
        os << "No stop";
    }
    else {
        for (const auto& bus : r.buses_for_stop_at_stop) {
            os << bus << " ";
        }
    }
    return os;
}

struct StopsForBusResponse {
    string bus;
    vector<pair<string, vector<string>>> stops_to_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    if (r.stops_to_buses.empty()) {
        os << "No bus";
    }
    else {
        bool first = true;
        for (const auto& stop_and_buses : r.stops_to_buses) {
            if (!first) {
                os << endl;
            }
            first = false;
            os << "Stop " << stop_and_buses.first << ":";
            if (stop_and_buses.second.size() == 1) {
                os << " no interchange";
            }
            else {
                for (const auto& other_bus : stop_and_buses.second) {
                    if (r.bus != other_bus) {
                        os << " " << other_bus;
                    }
                }
            }
        }
    }
    return os;
}

struct AllBusesResponse {
    map<string, vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {    
    if (r.buses_to_stops.empty()) {
        os << "No buses";
    }
    else {
        bool first = true;
        for (const auto& bus_item : r.buses_to_stops) {
            if (!first) {
                os << endl;
            }
            first = false;
            os << "Bus " << bus_item.first << ":";
            for (const auto& stop : bus_item.second) {
                os << " " << stop;
            }
        }
    }
    return os;
}

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) {
        buses_to_stops[bus] = stops;
        for (string stop : stops) {
            stops_to_buses[stop].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
        if (stops_to_buses.count(stop) == 0) {
            return BusesForStopResponse{ vector<string>() };
        }
        else {
            return BusesForStopResponse{ stops_to_buses.at(stop) };
        }
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const {
        vector<pair<string, vector<string>>> result;
        if (buses_to_stops.count(bus) > 0) {
            for (const auto& stop : buses_to_stops.at(bus)) {
                result.push_back(make_pair(stop, stops_to_buses.at(stop)));
            }
        }
        return StopsForBusResponse{ bus, result };
    }

    AllBusesResponse GetAllBuses() const {
        return AllBusesResponse{ buses_to_stops };        
    }
private:
    map<string, vector<string>> buses_to_stops, stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше
//void Vec() {
//    vector<int> values;
//    Time t;
//    for (size_t i = 0; i < 50000; i++) {
//        values.insert(values.begin(), i);
//    }
//}
//
//void Vec1() {
//    vector<int> values;
//    Time t;
//    for (size_t i = 0; i < 50000; i++) {
//        values.push_back(i);
//    }
//}
//
//int main() {
//    Vec();
//    Vec1();
//    /*vector<int> values;
//    Time t;
//    for (size_t i = 0; i < 50000; i++) {
//        values.insert(values.begin(), i);
//    }*/
//    return 0;
//}

int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
        case QueryType::NewBus:
            bm.AddBus(q.bus, q.stops);
            break;
        case QueryType::BusesForStop:
            cout << bm.GetBusesForStop(q.stop);
            break;
        case QueryType::StopsForBus:
            cout << bm.GetStopsForBus(q.bus);
            break;
        case QueryType::AllBuses:
            cout << bm.GetAllBuses();
            break;
        }
    }
    return 0;
}