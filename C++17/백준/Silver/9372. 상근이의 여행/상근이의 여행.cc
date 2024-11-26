#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int t, n, m;
int c[1001];
int v[1001];

int bfs(int sn, const vector<vector<int>>& lst) {
	queue<int> q;
	q.push(sn);
	v[sn] = 1;
	int cnt = 1;
	int result = 0;

	while (!q.empty()) {
		int cn = q.front(); q.pop();
		for (int nn : lst[cn]) {
			if (v[nn]) continue;
			v[nn] = 1;
			cnt++;
			result++;
			q.push(nn);
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; ++i) c[i] = i;

		vector<vector<int>> lst(n + 1);
		while (m--) {
			int sn, dn; cin >> sn >> dn;
			lst[sn].push_back(dn);
			lst[dn].push_back(sn);
		}

		memset(v, 0, sizeof(v));
		cout << bfs(1, lst) << "\n";
	}
}