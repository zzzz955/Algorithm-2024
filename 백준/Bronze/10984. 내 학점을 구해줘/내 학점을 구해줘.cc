#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main() {
	int t, n, c, i, j, p1;
	double g, p2;
	cin >> t;
	for (i = 0; i < t; i++) {
		cin >> n;
		p1 = 0;
		p2 = 0.0;
		for (j = 0; j < n; j++) {
			cin >> c >> g;
			p1 += c;
			p2 += g * c;
		}
		printf("%d %.1f\n", p1, p2 / p1);
	}
}