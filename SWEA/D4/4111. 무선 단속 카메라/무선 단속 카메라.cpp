#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t, n, k;

int main() {
	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		cin >> n >> k;

		vector<int> lst(n);
		for (int i = 0; i < n;++i) cin >> lst[i];
		sort(lst.begin(), lst.end());

		vector<int> dist;
		for (int i = 1; i < n; ++i) dist.push_back(lst[i] - lst[i - 1]);
		sort(dist.begin(), dist.end(), greater<int>());

		int ans = 0;
		for (int i = 0; i < k - 1 && i < n - 1; ++i) ans += dist[i];

		cout << "#" << tc << " " << lst[n - 1] - lst[0] - ans << "\n";
	}
}