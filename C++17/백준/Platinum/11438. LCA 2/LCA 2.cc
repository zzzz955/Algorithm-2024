#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX_N = 100001;
const int LOG = 20;

int n, m;
int depth[MAX_N];
int parent[MAX_N][LOG];
vector<int> tree[MAX_N];

void dfs(int node, int par, int dep) {
	depth[node] = dep;
	parent[node][0] = par;
	for (int child : tree[node]) {
		if (child != par) dfs(child, node, dep + 1);
	}
}

void pre_process() {
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= n; i++) {
			if (parent[i][j - 1] != -1) parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}
}

int lca(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);

	int diff = depth[u] - depth[v];
	for (int i = 0; i < LOG; i++) {
		if ((diff >> i) & 1) u = parent[u][i];
	}

	if (u == v) return u;

	for (int i = LOG - 1; i >= 0; i--) {
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

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1, -1, 0);
	pre_process();

	cin >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		cout << lca(a, b) << "\n";
	}
}