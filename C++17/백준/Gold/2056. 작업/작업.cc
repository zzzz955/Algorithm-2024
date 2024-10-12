#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<vector<int>> path(n + 1);
	vector<int> times(n + 1);
	for (int i = 1; i <= n; i++) {
		int t, c; cin >> t >> c;
		times[i] = t;
		while (c--) {
			int f; cin >> f;
			path[f].push_back(i);
		}
	}

	vector<int> cnt(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j : path[i]) cnt[j]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) if (!cnt[i]) q.push(i);
	
	vector<int> ans(n + 1, 0);
	while (!q.empty()) {
		int cn = q.front(); q.pop();
		ans[cn] += times[cn];
		for (int i : path[cn]) {
			ans[i] = max(ans[i], ans[cn]);
			if (!--cnt[i]) q.push(i);
		}
	}

	int max_val = 0;
	for (int i = 1; i <= n; i++) max_val = max(max_val, ans[i]);
	cout << max_val;
}