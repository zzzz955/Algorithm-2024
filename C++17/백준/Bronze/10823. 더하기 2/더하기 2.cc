#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	string s = "", temp;
	while (1) {
		getline(cin, temp);
		if (temp.empty()) break;
		else s += temp;
	}
	istringstream iss(s);
	int sum = 0;
	while (getline(iss, temp, ',')) {
		sum += stoi(temp);
	}
	cout << sum;
}