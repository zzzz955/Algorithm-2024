#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
	int sum = 0;
	string val, s;
	cin >> s;
	stringstream ss(s);
	while (getline(ss, val, ',')) {
		sum += stoi(val);
	}
	cout << sum;
}