#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> tree;

void build(vector<int>& lst, int node, int start, int end) {
	if (start == end) tree[node] = lst[start];
	else {
		int mid = (start + end) / 2;
		build(lst, node * 2, start, mid);
		build(lst, node * 2 + 1, mid + 1, end);
		tree[node] = tree[node * 2] * tree[node * 2 + 1];
	}
}

void update(int node, int start, int end, int idx, int val) {
	if (start == end) tree[node] = val;
	else {
		int mid = (start + end) / 2;
		if (start <= idx && idx <= mid) update(node * 2, start, mid, idx, val);
		else update(node * 2 + 1, mid + 1, end, idx, val);
		tree[node] = tree[node * 2] * tree[node * 2 + 1];
	}
}

int query(int node, int start, int end, int L, int R) {
	if (R < start || end < L) return 1;
	if (L <= start && end <= R) return tree[node];
	int mid = (start + end) / 2;
	int left = query(node * 2, start, mid, L, R);
	int right = query(node * 2 + 1, mid + 1, end, L, R);
	return left * right;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> n >> k) {
		vector<int> lst(n);
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			if (temp == 0) lst[i] = temp;
			else if (temp > 0) lst[i] = 1;
			else lst[i] = -1;
		}
		tree.resize(4 * n);
		build(lst, 1, 0, n - 1);

		while (k--) {
			char order;
			int a, b;
			cin >> order >> a >> b;
			if (order == 'C') {
				if (b == 0);
				else if (b > 0) b = 1;
				else b = -1;
				update(1, 0, n - 1, a - 1, b);
			}
			else {
				int num = query(1, 0, n - 1, a - 1, b - 1);
				if (num == 0) cout << 0;
				else if (num > 0) cout << '+';
				else cout << '-';
			}
		}
		cout << "\n";
	}
}