#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
using namespace std;

int n, m, ans, flag;
int nodes[501];
int v[501];

bool bfs(int sn, const vector<vector<int>>& lst) {
	queue<int> q;
	q.push(sn);
	v[sn] = 1;

	bool isTree = true;
	while (!q.empty()) {
		int cn = q.front(); q.pop();
		for (int nn : lst[cn]) {
			if (v[nn]) {
				if (v[nn] != v[cn] - 1) isTree = false;
				continue;
			}
			v[nn] = v[cn] + 1;
			q.push(nn);
		}
	}
	return isTree;
}

void solve() {
	vector<vector<int>> lst(n + 1);
	while (m--) {
		int par, child; cin >> par >> child;
		lst[par].push_back(child);
		lst[child].push_back(par);
	}

	ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (v[i]) continue;
		if (bfs(i, lst)) ans++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<string> result;
	int cases = 0;
	while (++cases) {
		cin >> n >> m;
		if (!n && !m) break;

		memset(v, 0, sizeof(v));
		solve();

		string temp = "Case " + to_string(cases) + ": ";
		if (ans > 1) temp += "A forest of " + to_string(ans) + " trees.\n";
		else if (ans == 1) temp += "There is one tree.\n";
		else temp += "No trees.\n";

		result.push_back(temp);
	}
	for (const string& r : result) cout << r;
}