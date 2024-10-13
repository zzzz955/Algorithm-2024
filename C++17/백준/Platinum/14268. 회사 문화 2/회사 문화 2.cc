#include<iostream>
#include<vector>

using namespace std;

const int MAX_N = 100001;
int tree[MAX_N * 4];
int lazy[MAX_N * 4];
int n, m;

vector<int> path[MAX_N];
int it[MAX_N];
int ot[MAX_N];
int timer;

void dfs(int boss) {
	it[boss] = ++timer;
	for (int child : path[boss]) dfs(child);
	ot[boss] = timer;
}

void propagate(int node, int s, int e) {
	if (lazy[node]) {
		tree[node] += (e - s + 1) * lazy[node];
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int s, int e, int L, int R, int val) {
	propagate(node, s, e);
	if (R < s || e < L) return;
	if (L <= s && e <= R) {
		lazy[node] += val;
		propagate(node, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, L, R, val);
	update(node * 2 + 1, mid + 1, e, L, R, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int s, int e, int idx) {
	propagate(node, s, e);
	if (s == idx && e == idx) return tree[node];
	int mid = (s + e) / 2;
	if (s <= idx && idx <= mid) return query(node * 2, s, mid, idx);
	else return query(node * 2 + 1, mid + 1, e, idx);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int trash;
	cin >> n >> m >> trash;
	for (int i = 2; i <= n; i++) {
		int boss; cin >> boss;
		path[boss].push_back(i);
	}

	dfs(1);

	while (m--) {
		int order, idx; cin >> order >> idx;
		if (order == 1) {
			int val; cin >> val;
			update(1, 1, n, it[idx], ot[idx], val);
		}
		else cout << query(1, 1, n, it[idx]) << "\n";
	}
}