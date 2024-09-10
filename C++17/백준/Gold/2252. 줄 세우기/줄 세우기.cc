#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<int> path[32001];

void input() {
	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		path[a].push_back(b);
	}
}

vector<int> solution() {
	vector<int> cnt(n + 1, 0);
	vector<int> result;
	for (int i = 1; i <= n; i++) {
		for (int node : path[i]) cnt[node]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!cnt[i]) q.push(i);
	}

	while (!q.empty()) {
		int node = q.front(); q.pop();
		result.push_back(node);
		for (int next : path[node]) {
			if (--cnt[next] == 0) q.push(next);
		}
	}

	if (result.size() == n) {
		return result;
	}
	else return {};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	vector<int> ans = solution();
	for (int s : ans) cout << s << " ";
}