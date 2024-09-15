#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int n, m;
vector<int> path[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		while (--a) {
			int c; cin >> c;
			path[b].push_back(c);
			b = c;
		}
	}

	vector<int> cnt(n + 1, 0);
	vector<int> result;
	for (int i = 1; i <= n; i++) {
		for (int j : path[i]) cnt[j]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!cnt[i]) q.push(i);
	}

	while (!q.empty()) {
		int cn = q.front(); q.pop();
		result.push_back(cn);
		for (int nn : path[cn]) {
			if (--cnt[nn] == 0) q.push(nn);
		}
	}

	if (result.size() != n) cout << 0;
	else for (int i : result) cout << i << "\n";
}