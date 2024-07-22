#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int length = s.size();
		if (s[length / 2 - 1] == s[length / 2]) cout << "Do-it\n";
		else cout << "Do-it-Not\n";
	}
}