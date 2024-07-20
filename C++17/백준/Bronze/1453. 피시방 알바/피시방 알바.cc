#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t, n, cnt = 0;
	cin >> t;
	vector<int> v(100, 0);
	while (t--) {
		cin >> n;
		if (!v[n - 1]) v[n - 1] = 1;
		else cnt++;
	}
	cout << cnt;
}