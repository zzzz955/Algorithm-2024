#include<iostream>

using namespace std;

const int MAX_N = 100000;
int nodes[MAX_N] = { 0, };
int tree[MAX_N * 4] = { 0, };
int lazy[MAX_N * 4] = { 0, };
int n, m;

void propagate(int node, int start, int end) {
	if (lazy[node]) {
		tree[node] = (end - start + 1) - tree[node];
		if (start != end) {
			lazy[node * 2] = lazy[node * 2] ? 0 : lazy[node];
			lazy[node * 2 + 1] = lazy[node * 2 + 1] ? 0 : lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int start, int end, int L, int R) {
	propagate(node, start, end);
	if (R < start || end < L) return;
	if (L <= start && end <= R) {
		lazy[node] = lazy[node] ? 0 : 1;
		propagate(node, start, end);
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, L, R);
	update(node * 2 + 1, mid + 1, end, L, R);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int start, int end, int L, int R) {
	propagate(node, start, end);
	if (R < start || end < L) return 0;
	if (L <= start && end <= R) return tree[node];
	int mid = (start + end) / 2;
	int left = query(node * 2, start, mid, L, R);
	int right = query(node * 2 + 1, mid + 1, end, L, R);
	return left + right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		if (!a) update(1, 0, n - 1, b - 1, c - 1);
		else cout << query(1, 0, n - 1, b - 1, c - 1) << "\n";
	}
}