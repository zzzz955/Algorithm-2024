#include<iostream>
using namespace std;

const int N = 2000001;
int n, t, x;
int tree[N * 4];

void update(int node, int s, int e, int idx, int val) {
	if (s == e) tree[node] += val;
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) update(node * 2, s, mid, idx, val);
		else update(node * 2 + 1, mid + 1, e, idx, val);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

int query(int node, int s, int e, int k) {
	if (s == e) return s;
	else {
		int mid = (s + e) / 2;
		if (tree[node * 2] >= k) return query(node * 2, s, mid, k);
		else return query(node * 2 + 1, mid + 1, e, k - tree[node * 2]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	while (n--) {
		cin >> t >> x;
		if (t == 1) update(1, 1, N - 1, x, 1);
		else {
			int result = query(1, 1, N - 1, x);
			cout << result << "\n";
			update(1, 1, N - 1, result, -1);
		}
	}
}