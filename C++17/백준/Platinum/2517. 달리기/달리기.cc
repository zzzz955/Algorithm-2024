#include<iostream>
#include<algorithm>
using namespace std;

const int N = 500000;
int n;
int lst[N];
int press[N];
int tree[N * 4];

void update(int node, int s, int e, int idx) {
	if (s == e) tree[node]++;
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) update(node * 2, s, mid, idx);
		else update(node * 2 + 1, mid + 1, e, idx);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

int query(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	int left = query(node * 2, s, mid, L, R);
	int right = query(node * 2 + 1, mid + 1, e, L, R);
	return left + right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> lst[i];
		press[i] = lst[i];
	}

	sort(press, press + n);
	for (int i = 0; i < n; ++i) {
		int idx = lower_bound(press, press + n, lst[i]) - press;
		update(1, 0, n - 1, idx);
		cout << query(1, 0, n - 1, idx, n - 1) << "\n";
	}
}