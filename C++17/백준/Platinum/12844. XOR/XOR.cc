#include<iostream>

using namespace std;

const int MAX_N = 500000;
int nodes[MAX_N];
int tree[MAX_N * 4];
int lazy[MAX_N * 4] = { 0, };
int n, m;

void build(int node, int start, int end) {
	if (start == end) tree[node] = nodes[start];
	else {
		int mid = (start + end) / 2;
		build(node * 2, start, mid);
		build(node * 2 + 1, mid + 1, end);
		tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
	}
}

void propagate(int node, int start, int end) {
	if (lazy[node]) {
		if ((end - start + 1) % 2) tree[node] ^= lazy[node];
		if (start != end) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int start, int end, int L, int R, int val) {
	propagate(node, start, end);
	if (R < start || end < L) return;
	if (L <= start && end <= R) {
		lazy[node] ^= val;
		propagate(node, start, end);
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, L, R, val);
	update(node * 2 + 1, mid + 1, end, L, R , val);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int query(int node, int start, int end, int L, int R) {
	propagate(node, start, end);
	if (R < start || end < L) return 0 ;
	if (L <= start && end <= R) return tree[node];
	int mid = (start + end) / 2;
	int left = query(node * 2, start, mid, L, R);
	int right = query(node * 2 + 1, mid + 1, end, L, R);
	return left ^ right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> nodes[i];
	build(1, 0, n - 1);
	cin >> m;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) {
			int d; cin >> d;
			update(1, 0, n - 1, b, c, d);
		}
		else cout << query(1, 0, n - 1, b, c) << "\n";
	}
}