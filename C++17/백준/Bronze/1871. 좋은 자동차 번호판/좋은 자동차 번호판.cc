#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();
	while (n--) {
		string s;
		cin >> s;
		stringstream ss(s);
		string front, back;
		getline(ss, front, '-');
		getline(ss, back, '-');
		int sum_front = 0;
		int sum_back = stoi(back);
		for (int i = 0; i < 3; i++) {
			sum_front += (front[i] - 65) * pow(26, 2 - i);
		}
		if (abs(sum_front - sum_back) <= 100) cout << "nice\n";
		else cout << "not nice\n";
	}
}