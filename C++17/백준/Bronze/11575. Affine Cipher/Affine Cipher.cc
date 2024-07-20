#include <iostream>

using namespace std;

int main() {
	int t, a, b;
	string s;
	cin >> t;
	while (t--) {
		cin >> a >> b >> s;
		int length = s.size();
		while (length--) {
			s[length] = 65 + ((a * s[length] - 65) + b) % 26;
		}
		cout << s << "\n";
	}
}