#include<iostream>
#include<vector>

using namespace std;

int tc, n, m;
vector<int> lst, tree;

void update(int node, int s, int e, int idx, int val) {
	if (s == idx && e == idx) {
		tree[node] += val;
		return;
	}
	int mid = (s + e) / 2;
	if (s <= idx && idx <= mid) update(node * 2, s, mid, idx, val);
	else update(node * 2 + 1, mid + 1, e, idx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	int left = query(node * 2, s, mid, L, R);
	int right = query(node * 2 + 1, mid + 1, e, L, R);
	return left + right;
}

void init() {
	lst.clear();
	tree.clear();
}

void input() {
	cin >> n >> m;
	lst.resize(n + 1);
	tree.resize((n + m) * 4, 0);
	for (int i = 1; i <= n; i++) {
		lst[i] = n - i + 1;
		update(1, 1, n + m, lst[i], 1);
	}
}

void solution() {
	int new_index = n + 1;
	for (int i = 1; i <= m; i++) {
		int a; cin >> a;
		int idx = lst[a];
		cout << query(1, 1, n + m, idx + 1, n + m) << " ";
		update(1, 1, n + m, idx, -1);
		update(1, 1, n + m, new_index, 1);
		lst[a] = new_index++;
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> tc;
	while (tc--) {
		init();
		input();
		solution();
	}
}