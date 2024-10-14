#include<iostream>
#include<vector>

using namespace std;

int n, m;
const int MAX_N = 100001;
int tree[MAX_N * 4];
int lazy[MAX_N * 4];

vector<int>path[MAX_N];
int it[MAX_N];
int ot[MAX_N];
int timer;

void dfs(int boss) {
	it[boss] = ++timer;
	for (int child : path[boss]) dfs(child);
	ot[boss] = timer;
}

void build(int node, int s, int e) {
	if (s == e) tree[node] = 1;
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

void propagate(int node, int s, int e) {
	if (lazy[node]) {
		if (lazy[node] == 1) {
			tree[node] = e - s + 1;
		}
		else if (lazy[node] == -1) {
			tree[node] = 0;
		}
		if (s != e) {
			lazy[node * 2] = lazy[node];
			lazy[node * 2 + 1] = lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int s, int e, int L, int R, int val) {
	propagate(node, s, e);
	if (R < s || e < L) return;
	if (L <= s && e <= R) {
		lazy[node] = val;
		propagate(node, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, L, R, val);
	update(node * 2 + 1, mid + 1, e, L, R, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int s, int e, int L, int R) {
	propagate(node, s, e);
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	int left = query(node * 2, s, mid, L, R);
	int right = query(node * 2 + 1, mid + 1, e, L, R);
	return left + right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int boss; cin >> boss;
		path[boss].push_back(i);
	}

	build(1, 1, n);
	dfs(1);

	cin >> m;
	while (m--) {
		int order, idx; cin >> order >> idx;
		if (order == 1) update(1, 1, n, it[idx] + 1, ot[idx], 1);
		else if (order == 2) update(1, 1, n, it[idx] + 1, ot[idx], -1);
		else cout << query(1, 1, n, it[idx] + 1, ot[idx]) << "\n";
	}
}