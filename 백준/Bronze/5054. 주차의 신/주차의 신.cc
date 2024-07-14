#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t, n, i, j, num;
	cin >> t;
	for (i = 0; i < t; i++) {
		cin >> n;
		vector<int> lst;
		for (j = 0; j < n; j++) {
			cin >> num;
			lst.push_back(num);
		}
		int ans = 0;
		int start = lst[0];
		int cur = start;
		sort(lst.begin(), lst.end());
		for (j = 0; j < n; j++) {
			ans += abs(cur - lst[j]);
			cur = lst[j];
		}
		ans += cur - start;
		cout << ans << "\n";
	}
}