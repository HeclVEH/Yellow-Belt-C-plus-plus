//Мой код
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

void PrintBusesForStop(map<string, vector<string>>& X,const string& x) {
	if (X.count(x) != 0 /*X.find(x) != X.end()*/) {
		for (const string& bus : X[x]) {
			cout << bus << " ";
		}
		cout << endl;
	}
	else {
		cout << "No stop" << endl;
	}
}

void PrintStopsForBus(map<string, vector<string>>& X,
	map<string, vector<string>>& Y, const string& x) {
	if (X.count(x) != 0/*X.find(x) != X.end()*/) {
		for (const auto& stop : X[x]) {
			cout << "Stop " << stop << ":";
			if (Y[stop].size() != 1) {
				for (const auto& bus : Y[stop]) {
					if (bus != x) {
						cout << " " << bus;
					}
				}
			}
			else {
				cout << " no interchange";
			}
			cout << endl;
		}
	}
	else {
		cout << "No bus" << endl;
	}
}

void PrintAllBuses(const map <string, vector<string>>& X) {
	if (X.empty() == false) {
		for (const auto& item : X) {
			cout << "Bus " << item.first << ":";
			for (const string& word : item.second) {
				cout << " " << word;
			}
			cout << endl;
		}
	}
	else {
		cout << "No buses" << endl;
	}
}


int main() {
	map <string, vector<string>> BS, SB;
	int q, qst;
	string command, bus, stop;
	cin >> q;
	for (int i = 0; i < q; ++i) {		
		cin >> command;
		if (command == "NEW_BUS") {
			cin >> bus;
			//if (BS.find(bus) == BS.end()) {
			cin >> qst;
			for (int i = 0; i < qst; ++i) {
				cin >> stop;
				BS[bus].push_back(stop);
				SB[stop].push_back(bus);
			}			
			//else {
			//	cout << "This bus " << bus << " already exist" << endl;
			//}
		}
		else if (command == "BUSES_FOR_STOP") {
			cin >> stop;
			PrintBusesForStop(SB, stop);			
		}
		else if (command == "STOPS_FOR_BUS") {
			cin >> bus;
			PrintStopsForBus(BS, SB, bus);		
		}
		else if (command == "ALL_BUSES") {
			PrintAllBuses(BS);			
		}
	}	
	return 0;
}