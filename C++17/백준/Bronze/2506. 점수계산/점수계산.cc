#include <iostream>

using namespace std;

int main() {
	int n, a, i;
	cin >> n;
	int ans = 0;
	int point = 0;
	for (i = 0; i < n; i++) {
		cin >> a;
		if (a == 1) {
			ans += ++point;
		}
		else {
			point = 0;
		}
	}
	cout << ans;
}