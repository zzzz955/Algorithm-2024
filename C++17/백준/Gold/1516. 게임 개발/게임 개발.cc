#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n;
int t[501];

vector<int> path[501];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		while (1) {
			int node; cin >> node;
			if (node == -1) break;
			path[node].push_back(i);
		}
	}
}

void solution() {
	vector<int> sum(n + 1, 0);
	vector<int> cnt(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int nn : path[i]) cnt[nn]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!cnt[i]) {
			q.push(i);
			sum[i] = t[i];
		}
	}

	while (!q.empty()) {
		int cn = q.front(); q.pop();
		for (int nn : path[cn]) {
			sum[nn] = max(sum[nn], sum[cn] + t[nn]);
			if (--cnt[nn] == 0) q.push(nn);
		}
	}

	for (int i = 1; i <= n; i++) cout << sum[i] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution();
}