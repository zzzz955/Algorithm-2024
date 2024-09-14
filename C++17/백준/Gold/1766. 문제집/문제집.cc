#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<int> path[32001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		path[a].push_back(b);
	}

	vector<int> cnt(n + 1, 0);
	for (int i = 1; i <= n; i++) for (int j : path[i]) cnt[j]++;

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++) if (!cnt[i]) pq.push(i);

	while (!pq.empty()) {
		int cn = pq.top(); pq.pop();
		cout << cn << " ";
		for (int i : path[cn]) if (--cnt[i] == 0) pq.push(i);
	}
}