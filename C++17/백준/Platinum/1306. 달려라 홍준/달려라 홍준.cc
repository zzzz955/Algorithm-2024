#include<iostream>
using namespace std;

const int M = 1e6 + 1;
int n, m;
int nodes[M];
int tree[M * 4];

void build(int node, int s, int e) {
	if (s == e) tree[node] = nodes[s];
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
	}
}

int query(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	return max(query(node * 2, s, mid, L, R), query(node * 2 + 1, mid + 1, e, L, R));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> nodes[i];

	build(1, 1, n);

	for (int i = m; i <= n - m + 1; ++i) {
		cout << query(1, 1, n, i - (m - 1), i + (m - 1)) << " ";
	}
}