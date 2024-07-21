#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s[0] == 'P') {
			cout << "skipped\n";
			continue;
		}
		else {
			string a, b;
			stringstream ss(s);
			getline(ss, a, '+');
			getline(ss, b, '+');
			cout << stoi(a) + stoi(b) << "\n";
		}
	}
}