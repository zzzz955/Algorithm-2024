#include<iostream>
#include<vector>

using namespace std;

const int MAX_N = 100001;
int n, m;
int up_tree[MAX_N * 4];
int down_tree[MAX_N * 4];
int lazy[MAX_N * 4];

vector<int> lst[MAX_N];
int it[MAX_N];
int ot[MAX_N];
int timer;

void dfs(int boss) {
	it[boss] = ++timer;
	for (int child : lst[boss]) dfs(child);
	ot[boss] = timer;
}

void propagate(int node, int s, int e) {
	if (lazy[node]) {
		down_tree[node] += (e - s + 1) * lazy[node];
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void up_update(int node, int s, int e, int idx, int val) {
	if (s == e) up_tree[node] += val;
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) up_update(node * 2, s, mid, idx, val);
		else up_update(node * 2 + 1, mid + 1, e, idx, val);
		up_tree[node] = up_tree[node * 2] + up_tree[node * 2 + 1];
	}
}

void down_update(int node, int s, int e, int L, int R, int val) {
	propagate(node, s, e);
	if (R < s || e < L) return;
	if (L <= s && e <= R) {
		lazy[node] += val;
		propagate(node, s, e);
		return;
	}
	int mid = (s + e) / 2;
	down_update(node * 2, s, mid, L, R, val);
	down_update(node * 2 + 1, mid + 1, e, L, R, val);
	down_tree[node] = down_tree[node * 2] + down_tree[node * 2 + 1];
}

int up_query(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return up_tree[node];
	int mid = (s + e) / 2;
	int left = up_query(node * 2, s, mid, L, R);
	int right = up_query(node * 2 + 1, mid + 1, e, L, R);
	return left + right;
}

int down_query(int node, int s, int e, int idx) {
	propagate(node, s, e);
	if (s == e) return down_tree[node];
	int mid = (s + e) / 2;
	if (idx <= mid) return down_query(node * 2, s, mid, idx);
	return down_query(node * 2 + 1, mid + 1, e, idx);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int trash;
	cin >> n >> m >> trash;
	for (int i = 2; i <= n; i++) {
		int boss; cin >> boss;
		lst[boss].push_back(i);
	}

	dfs(1);

	int flag = 1;
	while (m--) {
		int order; cin >> order;
		if (order == 1) {
			int idx, val; cin >> idx >> val;
			if (flag) down_update(1, 1, n, it[idx], ot[idx], val);
			else up_update(1, 1, n, it[idx], val);
		}
		else if (order == 2) {
			int idx; cin >> idx;
			cout << down_query(1, 1, n, it[idx]) + up_query(1, 1, n, it[idx], ot[idx]) << "\n";
		}
		else flag ^= 1;
	}
}