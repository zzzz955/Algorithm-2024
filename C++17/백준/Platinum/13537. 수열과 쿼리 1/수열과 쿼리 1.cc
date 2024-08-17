#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;
int n, m;

void build(vector<int>& lst, int node, int start, int end) {
	if (start == end) tree[node] = vector<int> (1, lst[start]);
	else {
		int mid = (start + end) / 2;
		build(lst, node * 2, start, mid);
		build(lst, node * 2 + 1, mid + 1, end);
		merge(tree[node * 2].begin(), tree[node * 2].end(), tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(), back_inserter(tree[node]));
	}
}

int query(int node, int start, int end, int L, int R, int val) {
	if (R < start || end < L) return 0;
	if (L <= start && end <= R) return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), val);
	int mid = (start + end) / 2;
	int left = query(node * 2, start, mid, L, R, val);
	int right = query(node * 2 + 1, mid + 1, end, L, R, val);
	return left + right;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	vector<int> lst(n);
	tree.resize(n * 4);
	for (int i = 0; i < n; i++) cin >> lst[i];
	build(lst, 1, 0, n - 1);
	cin >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << query(1, 0, n - 1, a - 1, b - 1, c) << "\n";
	}
}