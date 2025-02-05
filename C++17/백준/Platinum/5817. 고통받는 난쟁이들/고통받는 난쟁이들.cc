#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
const int N = 200001;
int lst[N];
int idx[N];
pair<int, int> tree[N * 4];

void build(int node, int s, int e) {
	if (s == e) tree[node] = { lst[s], lst[s] };
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		tree[node] = { max(tree[node * 2].first, tree[node * 2 + 1].first), min(tree[node * 2].second, tree[node * 2 + 1].second) };
	}
}

void update(int node, int s, int e, int idx, int val) {
	if (s == e) tree[node] = { val, val };
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) update(node * 2, s, mid, idx, val);
		else update(node * 2 + 1, mid + 1, e, idx, val);
		tree[node] = { max(tree[node * 2].first, tree[node * 2 + 1].first), min(tree[node * 2].second, tree[node * 2 + 1].second) };
	}
}

pair<int, int> query(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return { -1, 200001 };
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	pair<int, int> left = query(node * 2, s, mid, L, R);
	pair<int, int> right = query(node * 2 + 1, mid + 1, e, L, R);
	return { max(left.first, right.first), min(left.second, right.second) };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> idx[i];
		lst[idx[i]] = i;
	}
	build(1, 1, n);
	while (m--) {
		int op, x, y; cin >> op >> x >> y;
		if (op == 1) {
			update(1, 1, n, idx[x], y);
			update(1, 1, n, idx[y], x);
			swap(lst[idx[x]], lst[idx[y]]);
			swap(idx[x], idx[y]);
		}
		else {
			pair<int, int> result = query(1, 1, n, x, y);
			if (result.first - result.second == y - x) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}