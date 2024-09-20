#include<iostream>
#include<vector>

using namespace std;

int n, r, q;
vector<int> dp;
int v[100001] = { 0, };
vector<int> path[100001];

void dfs(int node) {
	for (int child : path[node]) {
		if (!v[child]) {
			v[child] = 1;
			dfs(child);
			dp[node] += dp[child];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r >> q;
	dp.resize(n + 1, 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		path[a].push_back(b);
		path[b].push_back(a);
	}
	v[r] = 1;
	dfs(r);
	while (q--) {
		int a; cin >> a;
		cout << dp[a] << "\n";
	}
}