#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX_N = 100001;
const int LOG = 18;

int n, m;
int nodes[MAX_N];
int depth[MAX_N];
int parents[MAX_N][LOG];

vector<int> lst[MAX_N];

void dfs(int node, int par, int dep) {
	depth[node] = dep;
	parents[node][0] = par;

	for (int child : lst[node]) {
		if (child != par) dfs(child, node, dep + 1);
	}
}

void preprocess() {
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= n; i++) {
			if (parents[i][j - 1] != -1) parents[i][j] = parents[parents[i][j - 1]][j - 1];
		}
	}
}

int lca(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);

	int diff = depth[u] - depth[v];
	for (int i = 0; i < LOG; i++) {
		if ((diff >> i) & 1) u = parents[u][i];
	}

	if (u == v) return u;

	for (int i = LOG - 1; i >= 0; i--) {
		if (parents[u][i] != parents[v][i]) {
			u = parents[u][i];
			v = parents[v][i];
		}
	}

	return parents[u][0];
}

int newRoot(int r, int u, int v) {
	int ru = lca(r, u);
	int uv = lca(u, v);
	int rv = lca(r, v);

	if (depth[ru] > depth[uv] && depth[ru] > depth[rv]) return ru;
	if (depth[uv] > depth[ru] && depth[uv] > depth[rv]) return uv;
	return rv;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) nodes[i] = i;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		lst[a].push_back(b);
		lst[b].push_back(a);
	}

	dfs(1, -1, 0);
	preprocess();

	cin >> m;
	while (m--) {
		int r, u, v; cin >> r >> u >> v;
		cout << newRoot(r, u, v) << "\n";
	}
}