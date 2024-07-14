#include <iostream>

using namespace std;

int main() {
	int t, s, n, q, p, i, j;
	cin >> t;
	for (i = 0; i < t; i++) {
		cin >> s >> n;
		for (j = 0; j < n; j++) {
			cin >> q >> p;
			s += q * p;
		}
		cout << s << "\n";
	}
}