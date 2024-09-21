#include<iostream>
#include<vector>

using namespace std;

const int MAX_N = 100000;
int nodes[MAX_N];
pair<int, int> tree[MAX_N * 4];
int n, m;
int idx, val;

void build(int node, int start, int end) {
	if (start == end) tree[node] = { nodes[start], start };
	else {
		int mid = (start + end) / 2;
		build(node * 2, start, mid);
		build(node * 2 + 1, mid + 1, end);
		if (tree[node * 2].first >= tree[node * 2 + 1].first) tree[node] = tree[node * 2];
		else tree[node] = tree[node * 2 + 1];
	}
}

void update(int node, int start, int end, int idx, int val) {
	if (start == end) tree[node] = { val, idx };
	else {
		int mid = (start + end) / 2;
		if (start <= idx && idx <= mid) update(node * 2, start, mid, idx, val);
		else update(node * 2 + 1, mid + 1, end, idx, val);
		if (tree[node * 2].first >= tree[node * 2 + 1].first) tree[node] = tree[node * 2];
		else tree[node] = tree[node * 2 + 1];
	}
}

pair<int, int> query(int node, int start, int end, int L, int R) {
	if (R < start || end < L) return { 0, -1 };
	if (L <= start && end <= R) return tree[node];
	int mid = (start + end) / 2;
	pair<int, int> left = query(node * 2, start, mid, L, R);
	pair<int, int> right = query(node * 2 + 1, mid + 1, end, L, R);
	if (left.first >= right.first) return left;
	return right;
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
		if (a == 1) update(1, 0, n - 1, b - 1, c);
		else {
			pair<int, int> max1 = query(1, 0, n - 1, b - 1, c - 1);
			update(1, 0, n - 1, max1.second, 0);
			pair<int, int> max2 = query(1, 0, n - 1, b - 1, c - 1);
			update(1, 0, n - 1, max1.second, max1.first);
			cout << max1.first + max2.first << "\n";
		}
	}
}