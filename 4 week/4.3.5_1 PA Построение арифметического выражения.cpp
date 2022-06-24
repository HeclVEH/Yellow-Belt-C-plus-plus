#include <string>
#include <iostream>
#include <iterator>

using namespace std;

int main() {
	int query, num;
	cin >> num >> query;
	string result;
	result = to_string(num);
	cin.ignore(32767, '\n');
	while (query != 0) {	
		string tmp;		
		getline(cin, tmp);
		result.insert(0, "(");
		result += ") ";
		result += tmp;
		//cout << result;
		--query;
	}
	cout << result;	
	return 0;
}