#include<iostream>
#define ll long long

using namespace std;
const ll MAX_N = 500001;
ll nodes[MAX_N];
ll index[MAX_N * 2];
ll tree[MAX_N * 4];
ll n, ans;

void update(ll node, ll s, ll e, ll idx) {
	if (s == idx && idx == e) {
		tree[node] = 1;
		return;
	}
	ll mid = (s + e) / 2;
	if (s <= idx && idx <= mid) update(node * 2, s, mid, idx);
	else update(node * 2 + 1, mid + 1, e, idx);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(ll node, ll s, ll e, ll L, ll R) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node];
	ll mid = (s + e) / 2;
	ll left = query(node * 2, s, mid, L, R);
	ll right = query(node * 2 + 1, mid + 1, e, L, R);
	return left + right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> nodes[i];
	for (int i = 0; i < n; i++) {
		ll num; cin >> num;
		index[num] = i;
	}
	for (int i = 0; i < n; i++) {
		ll idx = index[nodes[i]];
		ans += query(1, 0, n - 1, idx + 1, n - 1);
		update(1, 0, n - 1, idx);
	}
	cout << ans;
}