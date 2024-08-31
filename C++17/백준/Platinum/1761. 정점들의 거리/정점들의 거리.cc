#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, root;
const int MAX_N = 40001;
const int LOG = 17;
int parent[MAX_N][LOG];
int depth[MAX_N];
int cost[MAX_N];
int nodes[MAX_N];
vector<pair<int, int>> tree[MAX_N];

int Find(int a) {
	if (nodes[a] == a) return a;
	return nodes[a] = Find(nodes[a]);
}

void Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);
	if (A == B) return;
	nodes[B] = A;
}

void init() {
	cin >> n;
	for (int i = 1; i <= n; i++) nodes[i] = i;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c; cin >> a >> b >> c;
		tree[a].push_back({ b, c });
		tree[b].push_back({ a, c });
		Union(a, b);
	}
	for (int i = 1; i <= n; i++) {
		if (nodes[i] == i) {
			root = i;
			break;
		}
	}
}

void dfs(int node, int p, int d, int c) {
	parent[node][0] = p;
	depth[node] = d;
	cost[node] = c;
	for (pair<int, int> next : tree[node]) {
		int child = next.first, nc = next.second;
		if (child != p) dfs(child, node, d + 1, c + nc);
	}
}

void pre_process() {
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= n; i++) {
			if (parent[i][j - 1] != -1) parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	int diff = depth[a] - depth[b];
	for (int i = 0; i < LOG; i++) {
		if ((diff >> i) & 1) a = parent[a][i];
	}
	if (a == b) return a;
	for (int i = LOG - 1; i >= 0; i--) {
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return parent[a][0];
}

void query() {
	cin >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		int par = lca(a, b);
		cout << cost[a] + cost[b] - cost[par] * 2 << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	init();
	dfs(root, -1, 0, 0);
	pre_process();
	query();
}