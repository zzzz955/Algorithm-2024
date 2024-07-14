#include <iostream>

using namespace std;

int main() {
	int n, i, j, ans = 0;
	cin >> n;
	for (i = 0; i <= n; i++) {
		for (j = i; j <= n; j++) {
			ans += i;
			ans += j;
		}
	}
	cout << ans;
}