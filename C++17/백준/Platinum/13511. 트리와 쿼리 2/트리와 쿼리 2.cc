#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX_N = 100001;
const int LOG = 20;

int n, m;
int p[MAX_N][LOG];
int depth[MAX_N];
long long cost[MAX_N];
int v[MAX_N];
vector<pair<int, int>> tree[MAX_N];

void input() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c; cin >> a >> b >> c;
		tree[a].push_back({ b, c });
		tree[b].push_back({ a, c });
	}
}

void dfs(int node, int par, int dep, long long cos) {
	p[node][0] = par;
	depth[node] = dep;
	cost[node] = cos;
	
	for (pair<int, int> next : tree[node]) {
		int child = next.first, c = next.second;
		if (!v[child]) {
			v[child] = 1;
			dfs(child, node, dep + 1, cos + c);
		}
	}
}

void pre_process() {
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= n; i++) {
			if (p[i][j - 1] != -1) p[i][j] = p[p[i][j - 1]][j - 1];
		}
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	
	int diff = depth[a] - depth[b];
	for (int i = 0; i < LOG; i++) {
		if ((diff >> i) & 1) a = p[a][i];
	}

	if (a == b) return a;

	for (int i = LOG - 1; i >= 0; i--) {
		if (p[a][i] != p[b][i]) {
			a = p[a][i];
			b = p[b][i];
		}
	}

	return p[a][0];
}

int Find(int a, int d) {
	for (int i = 0; i < LOG; i++) {
		if ((d >> i) & 1) a = p[a][i];
	}
	return a;
}

void query() {
	cin >> m;
	while (m--) {
		int a; cin >> a;
		if (a == 1) {
			int n1, n2; cin >> n1 >> n2;
			int par = lca(n1, n2);
			cout << cost[n1] + cost[n2] - cost[par] * 2 << "\n";
		}
		else {
			int n1, n2, k; cin >> n1 >> n2 >> k;
			k--;
			int par = lca(n1, n2);
			int left = depth[n1] - depth[par];
			int right = depth[n2] - depth[par];
			if (left >= k) cout << Find(n1, k) << "\n";
			else cout << Find(n2, right - (k - left)) << "\n";
		}
	}
}

void solution() {
	v[1] = 1;
	dfs(1, -1, 0, 0);
	pre_process();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution();
	query();
}