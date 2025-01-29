#include<iostream>
using namespace std;

const int N = 250000;
const int P = 65535;
int n, k;
int lst[N];
int tree[P * 4];

void update(int node, int s, int e, int idx, int val) {
	if (s == e) tree[node] += val;
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) update(node * 2, s, mid, idx, val);
		else update(node * 2 + 1, mid + 1, e, idx, val);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

int query(int node, int s, int e, int idx) {
	if (s == e) return s;
	int mid = (s + e) / 2;
	if (idx <= tree[node * 2]) return query(node * 2, s, mid, idx);
	else return query(node * 2 + 1, mid + 1, e, idx - tree[node * 2]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> lst[i];
	for (int i = 0; i < k; ++i) {
		update(1, 0, P, lst[i], 1);
	}

	long long ans = query(1, 0, P, (k + 1) / 2);
	for (int i = k; i < n; ++i) {
		update(1, 0, P, lst[i - k], -1);
		update(1, 0, P, lst[i], 1);
		ans += query(1, 0, P, (k + 1) / 2);
	}
	cout << ans;
}