#include<iostream>
#include<vector>
#define ll long long
using namespace std;

const int N = 200000;
const int MOD = 1000000007;
int n;
pair<ll, int> tree[N * 4];

void update(int node, int s, int e, ll idx) {
	if (s == e) {
		tree[node].first += idx;
		tree[node].second++;
	}
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) update(node * 2, s, mid, idx);
		else update(node * 2 + 1, mid + 1, e, idx);
		tree[node] = { tree[node * 2].first + tree[node * 2 + 1].first, tree[node * 2].second + tree[node * 2 + 1].second };
	}
}

pair<ll, int> query(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return { 0, 0 };
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	pair<ll, int> left = query(node * 2, s, mid, L, R);
	pair<ll, int> right = query(node * 2 + 1, mid + 1, e, L, R);
	return { left.first + right.first, left.second + right.second };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<ll> results;
	for (int i = 0; i < n; ++i) {
		ll num; cin >> num;
		update(1, 0, N, num);
		pair<ll, int> left = query(1, 0, N, 0, num - 1);
		pair<ll, int> right = query(1, 0, N, num + 1, N);
		ll result = abs(left.first - num * left.second) + abs(right.first - num * right.second);
		if (i) results.push_back(result % MOD);
	}
	ll ans = 1;
	for (ll i : results) ans = (ans * i) % MOD;
	cout << ans;
}