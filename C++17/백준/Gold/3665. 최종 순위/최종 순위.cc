#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int tc, n, m;
vector<int> lst;
vector<int> cnt;
vector<int> result;
vector<vector<int>> path;

void init() {
	lst.clear();
	cnt.clear();
	result.clear();
	path.clear();
}

void input() {
	cin >> n;
	lst.resize(n + 1);
	cnt.resize(n + 1, 0);
	path.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> lst[i];
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			path[lst[i]].push_back(lst[j]);
		}
	}
	cin >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		auto it = find(path[a].begin(), path[a].end(), b);
		if (it != path[a].end()) {
			path[a].erase(it);
			path[b].push_back(a);
		}
		else {
			auto it = find(path[b].begin(), path[b].end(), a);
			path[b].erase(it);
			path[a].push_back(b);
		}
	}
}

void solution() {
	for (int i = 1; i <= n; i++) {
		for (int j : path[lst[i]]) cnt[j]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!cnt[lst[i]]) q.push(lst[i]);
	}

	while (!q.empty()) {
		int cn = q.front(); q.pop();
		result.push_back(cn);
		for (int nn : path[cn]) {
			if (--cnt[nn] == 0) q.push(nn);
		}
	}

	if (result.size() == n) {
		for (int i : result) cout << i << " ";
		cout << "\n";
	}
	else {
		cout << "IMPOSSIBLE\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		init();
		input();
		solution();
	}
}