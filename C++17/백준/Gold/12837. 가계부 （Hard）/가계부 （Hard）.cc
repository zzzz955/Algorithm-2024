#include <iostream>
#include <vector>

using namespace std;

int n, q;
vector<long long> tree;

void update(int node, int start, int end, int idx, int val) {
	if (start == end) tree[node] += val;
	else {
		int mid = (start + end) / 2;
		if (start <= idx && idx <= mid) {
			update(node * 2, start, mid, idx, val);
		}
		else {
			update(node * 2 + 1, mid + 1, end, idx, val);
		}
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

long long query(int node, int start, int end, int L, int R) {
	if (R < start || end < L) return 0;
	if (L <= start && end <= R) return tree[node];
	int mid = (start + end) / 2;
	long long left = query(node * 2, start, mid, L, R);
	long long right = query(node * 2 + 1, mid + 1, end, L, R);
	return left + right;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	tree.resize(n * 4, 0);
	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) update(1, 0, n - 1, b - 1, c);
		else cout << query(1, 0, n - 1, b - 1, c - 1) << "\n";
	}
}