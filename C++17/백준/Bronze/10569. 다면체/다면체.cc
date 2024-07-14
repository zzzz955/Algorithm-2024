#include <iostream>

using namespace std;

int main() {
	int t, a, b, i, ans;
	cin >> t;
	for (i = 1; i <= t; i++) {
		cin >> a >> b;
		ans = 2 - a + b;
		cout << ans << "\n";
	}
}