#include<iostream>
#define ll long long

using namespace std;

const ll MAX_N = 1000000;
ll nodes[MAX_N];
ll tree[MAX_N * 4] = { 0, };
ll lazy[MAX_N * 4] = { 0, };
ll n, m, k;

void build(ll node, ll start, ll end) {
	if (start == end) tree[node] = nodes[start];
	else {
		ll mid = (start + end) / 2;
		build(node * 2, start, mid);
		build(node * 2 + 1, mid + 1, end);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

void propagate(ll node, ll start, ll end) {
	if (lazy[node]) {
		tree[node] += (end - start + 1) * lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(ll node, ll start, ll end, ll L, ll R, ll val) {
	propagate(node, start, end);
	if (R < start || end < L) return;
	if (L <= start && end <= R) {
		tree[node] += (end - start + 1) * val;
		if (start != end) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	ll mid = (start + end) / 2;
	update(node * 2, start, mid, L, R, val);
	update(node * 2 + 1, mid + 1, end, L, R, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(ll node, ll start, ll end, ll L, ll R) {
	propagate(node, start, end);
	if (R < start || end < L) return 0;
	if (L <= start && end <= R) return tree[node];
	ll mid = (start + end) / 2;
	ll left = query(node * 2, start, mid, L, R);
	ll right = query(node * 2 + 1, mid + 1, end, L, R);
	return left + right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (ll i = 0; i < n; i++) cin >> nodes[i];
	build(1, 0, n - 1);
	ll q = m + k;
	while (q--) {
		ll a, b, c; cin >> a >> b >> c;
		if (a == 1) {
			ll d; cin >> d;
			update(1, 0, n - 1, b - 1, c - 1, d);
		}
		else {
			cout << query(1, 0, n - 1, b - 1, c - 1) << "\n";
		}
	}
}