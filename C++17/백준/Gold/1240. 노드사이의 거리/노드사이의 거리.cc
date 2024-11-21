#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int LOG = 11;
const int N = 1001;

int n, m;
int depth[N];
int cost[N];
int parent[N][LOG];

struct Edge {
	int nn, w;
};
vector<Edge> lst[1001];

void dfs(int par, int node, int dep, int val) {
	parent[node][0] = par;
	depth[node] = dep;
	cost[node] = val;

	for (const Edge& edge : lst[node]) {
		if (edge.nn == par) continue;
		dfs(node, edge.nn, dep + 1, val + edge.w);
	}
}

void preprocess() {
	for (int j = 1; j < LOG; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (parent[i][j - 1] != -1) parent[i][j] = parent[parent[i][j - 1]][j - 1];
			else parent[i][j] = -1;
		}
	}
}

int lca(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);

	int diff = depth[u] - depth[v];
	for (int i = LOG - 1; i >= 0; --i) {
		if ((diff >> i) & 1) u = parent[u][i];
	}

	if (u == v) return u;

	for (int i = LOG - 1; i >= 0; --i) {
		if (parent[u][i] != parent[v][i]) {
			u = parent[u][i];
			v = parent[v][i];
		}
	}

	return parent[u][0];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n - 1; ++i) {
		int a, b, c; cin >> a >> b >> c;
		lst[a].push_back({b, c});
		lst[b].push_back({ a, c });
	}

	dfs(-1, 1, 0, 0);
	preprocess();

	while (m--) {
		int a, b; cin >> a >> b;
		int LCA = lca(a, b);
		cout << cost[a] + cost[b] - cost[LCA] * 2 << "\n";
	}
}