#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int cnt = 0;
	while (a <= b) {
		cnt++;
		if (a == b) break;
		if (b % 10 == 1) {
			b /= 10;
			continue;
		}
		else if (b % 2 == 0) {
			b /= 2;
		}
		else {
			cout << -1;
			return 0;
		}
	}
	if (a > b) cout << -1;
	else cout << cnt;
}
