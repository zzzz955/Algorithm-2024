#include<iostream>
#define ll long long

using namespace std;
ll n, q1, q2;
ll nodes[1000000];
ll tree[4000000];
ll lazy[4000000];

void build(ll node, ll s, ll e) {
	if (s == e) tree[node] = nodes[s];
	else {
		ll m = (s + e) / 2;
		build(node * 2, s, m);
		build(node * 2 + 1, m + 1, e);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

void propagate(ll node, ll s, ll e) {
	if (lazy[node]) {
		tree[node] += (e - s + 1) * lazy[node];
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(ll node, ll s, ll e, ll l, ll r, ll v) {
	propagate(node, s, e);
	if (r < s || e < l) return;
	if (l <= s && e <= r) {
		lazy[node] += v;
		propagate(node, s, e);
		return;
	}
	ll m = (s + e) / 2;
	update(node * 2, s, m, l, r, v);
	update(node * 2 + 1, m + 1, e, l, r, v);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(ll node, ll s, ll e, ll l, ll r) {
	propagate(node, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return tree[node];
	ll m = (s + e) / 2;
	ll left = query(node * 2, s, m, l, r);
	ll right = query(node * 2 + 1, m + 1, e, l, r);
	return left + right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q1 >> q2;
	for (ll i = 0; i < n; i++) cin >> nodes[i];
	build(1, 0, n - 1);
	ll m = q1 + q2;
	while (m--) {
		ll op; cin >> op;
		if (op == 1) {
			ll l, r; cin >> l >> r;
			cout << query(1, 0, n - 1, l - 1, r - 1) << "\n";
		}
		else {
			ll l, r, v; cin >> l >> r >> v;
			update(1, 0, n - 1, l - 1, r - 1, v);
		}
	}
}