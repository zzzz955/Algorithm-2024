#include<iostream>
using namespace std;

int a, b, c, ans;

int main() {
	cin >> a >> b >> c;
	while (1) {
		if (b - a < c - b) {
			a = b;
			b = c - 1;
		}
		else {
			c = b;
			b = a + 1;
		}

		if (a != b && a != c && b != c) ans++;
		else break;
	}
	cout << ans;
}