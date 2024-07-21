#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
	int c, n, m, u, t;
	cin >> c;
	while (c--) {
		cin >> n >> m;
		u = m * 2 - n;
		m -= u;
		cout << u << " " << m << "\n";
	}
}