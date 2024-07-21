#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();
	while (n--) {
		int sum = 0, val;
		string s;
		getline(cin, s);
		istringstream iss(s);
		while (iss >> val) sum += val;
		cout << sum << "\n";
	}
}