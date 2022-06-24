#include <string>
#include <iostream>
#include <iterator>
#include <deque>

using namespace std;

int main() {
	int query, num, q_max;
	char prev_char;
	cin >> num >> query;
	string tmp_num;
	deque<string> result;
	tmp_num = to_string(num);
	q_max = query;
	result.push_back(tmp_num);
	cin.ignore(32767, '\n');
	while (query != 0) {
		string tmp;
		getline(cin, tmp);		
		if (query == q_max) {
			result.push_back(" ");
			result.push_back(tmp);
		}
		else {
			if (tmp[0] == '+' || tmp[0] == '-') {
				result.push_back(" ");
				result.push_back(tmp);
			}
			else {
				if (prev_char == '*' || prev_char == '/') {
					result.push_back(" ");
					result.push_back(tmp);
				}
				else {
					result.push_front("(");
					result.push_back(") ");
					result.push_back(tmp);					 
				}
			}
		}
		prev_char = tmp[0];
		//cout << result;
		--query;
	}
	for (auto item : result) {
		cout << item;
	}
	cout << endl;
	return 0;
}