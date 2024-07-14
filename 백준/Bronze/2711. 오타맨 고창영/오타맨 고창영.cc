#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t, p, i, j;
	cin >> t;
	for (i = 0; i < t; i++) {
		char s[81];
		cin >> p >> s;
		for (j = 0; j < 81; j++) {
			if (s[j] == '\0') break;
			if (j != p - 1) cout << s[j];
		}
		cout << "\n";
	}
}