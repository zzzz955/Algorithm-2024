#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

const int N = 500000;
int n;
vector<pair<int, int>> lst;
ll tree[N * 4];
ll ans;

void update(int node, int s, int e, int idx) {
	if (s == e) tree[node]++;
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) update(node * 2, s, mid, idx);
		else update(node * 2 + 1, mid + 1, e, idx);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

ll query(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	ll left = query(node * 2, s, mid, L, R);
	ll right = query(node * 2 + 1, mid + 1, e, L, R);
	return left + right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	lst.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> lst[i].first;
		lst[i].second = i;
	}
	sort(lst.begin(), lst.end());

	for (int i = 0; i < n; ++i) {
		ans += i - query(1, 0, n - 1, 0, lst[i].second);
		update(1, 0, n - 1, lst[i].second);
	}
	cout << ans;
}