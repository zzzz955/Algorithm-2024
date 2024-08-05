#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> tree;

void build(vector<int>& lst, int node, int start, int end) {
	if (start == end) {
		tree[node] = lst[start];
	}
	else {
		int mid = (start + end) / 2;
		build(lst, node * 2, start, mid);
		build(lst, node * 2 + 1, mid + 1, end);
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	}
}

void update(int node, int start, int end, int idx, int val) {
	if (start == end) {
		tree[node] = val;
	}
	else {
		int mid = (start + end) / 2;
		if (start <= idx && idx <= mid) {
			update(node * 2, start, mid, idx, val);
		}
		else {
			update(node * 2 + 1, mid + 1, end, idx, val);
		}
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	}
}

int query(int node, int start, int end, int L, int R) {
	if (R < start || end < L) {
		return 1000000001;
	}
	if (L <= start && end <= R) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	int left = query(node * 2, start, mid, L, R);
	int right = query(node * 2 + 1, mid + 1, end, L, R);
	return min(left, right);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<int> lst(n);
	tree.resize(n * 4);
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
	}
	build(lst, 1, 0, n - 1);
	cin >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) update(1, 0, n - 1, b - 1, c);
		else cout << query(1, 0, n - 1, b - 1, c - 1) << "\n";
	}
}