#include<iostream>
#include<vector>
#define ll long long
using namespace std;

const ll MAX_N = 500001;
ll n, m;
ll nodes[MAX_N];
ll tree[MAX_N * 4];
ll lazy[MAX_N * 4];

ll it[MAX_N];
ll sal[MAX_N];
ll ot[MAX_N];
ll t;
vector<ll> parent[MAX_N];

void dfs(ll cn) {
	it[cn] = ++t;
	sal[t] = nodes[cn];
	for (ll nn : parent[cn]) dfs(nn);
	ot[cn] = t;
}

void build(ll node, ll s, ll e) {
	if (s == e) tree[node] = sal[s];
	else {
		ll mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
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

void update(ll node, ll s, ll e, ll L, ll R, ll val) {
	propagate(node, s, e);
	if (R < s || e < L) return;
	if (L <= s && e <= R) {
		lazy[node] += val;
		propagate(node, s, e);
		return;
	}
	ll mid = (s + e) / 2;
	update(node * 2, s, mid, L, R, val);
	update(node * 2 + 1, mid + 1, e, L, R, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(ll node, ll s, ll e, ll idx) {
	propagate(node, s, e);
	if (s == e) return tree[node];
	ll mid = (s + e) / 2;
	if (idx <= mid) return query(node * 2, s, mid, idx);
	return query(node * 2 + 1, mid + 1, e, idx);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> nodes[1];
	for (ll i = 2; i <= n; i++) {
		ll par; cin >> nodes[i] >> par;
		parent[par].push_back(i);
	}

	dfs(1);
	build(1, 1, n);

	while (m--) {
		char order; cin >> order;
		if (order == 'p') {
			ll idx, val; cin >> idx >> val;
			update(1, 1, n, it[idx] + 1, ot[idx], val);
		}
		else {
			ll idx; cin >> idx;
			cout << query(1, 1, n, it[idx]) << "\n";
		}
	}
}