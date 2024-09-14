#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX_N = 100001;
const int LOG = 20;

int n, k;
int par[MAX_N][LOG];
int mn[MAX_N][LOG];
int mx[MAX_N][LOG];
int dep[MAX_N];
int nodes[MAX_N];

struct Link {
	int e, w;
};
vector<Link> links[MAX_N];

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

void dfs(int node, int parent, int depth, int c) {
	par[node][0] = parent;
	mn[node][0] = c;
	mx[node][0] = c;
	dep[node] = depth;
	for (Link link : links[node]) {
		int child = link.e, w = link.w;
		if (parent != child) dfs(child, node, depth + 1, w);
	}
}

void preprocess() {
	for (int i = 1; i < LOG; i++) {
		for (int j = 1; j <= n; j++) {
			if (par[j][i - 1] != -1) {
				par[j][i] = par[par[j][i - 1]][i - 1];
				mn[j][i] = min(mn[par[j][i - 1]][i - 1], mn[j][i - 1]);
				mx[j][i] = max(mx[par[j][i - 1]][i - 1], mx[j][i - 1]);
			}
		}
	}
}

pair<int, int> lca(int u, int v) {
	int min_val = 2e9, max_val = -1;
	if (dep[u] < dep[v]) swap(u, v);
	
	int diff = dep[u] - dep[v];
	for (int i = 0; i < LOG; i++) {
		if ((diff >> i) & 1) {
			min_val = min(min_val, mn[u][i]);
			max_val = max(max_val, mx[u][i]);
			u = par[u][i];
		}
	}

	if (u == v) return { min_val, max_val };

	for (int i = LOG - 1; i >= 0; i--) {
		if (par[u][i] != par[v][i]) {
			min_val = min({ min_val, mn[u][i], mn[v][i] });
			max_val = max({ max_val, mx[u][i], mx[v][i] });
			u = par[u][i];
			v = par[v][i];
		}
	}

	min_val = min({ min_val, mn[u][0], mn[v][0] });
	max_val = max({ max_val, mx[u][0], mx[v][0] });

	return { min_val, max_val };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) nodes[i] = i;

	for (int i = 1; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		links[a].push_back({ b, c });
		links[b].push_back({ a, c });
		Union(a, b);
	}

	int root = 1;
	for (int i = 1; i <= n; i++) if (nodes[i] == i) {
		root = i; break;
	}

	dfs(root, -1, 0, 0);
	preprocess();

	cin >> k;
	while (k--) {
		int a, b; cin >> a >> b;
		pair<int, int> ans = lca(a, b);
		cout << ans.first << " " << ans.second << "\n";
	}
}