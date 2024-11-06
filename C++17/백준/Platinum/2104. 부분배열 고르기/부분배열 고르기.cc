#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

ll n;
const ll MAX_N = 100000;
ll nodes[MAX_N];
ll minTree[MAX_N * 4];
ll sumTree[MAX_N * 4];

void minBuild(ll node, ll s, ll e) {
	if (s == e) minTree[node] = s;
	else {
		ll mid = (s + e) / 2;
		minBuild(node * 2, s, mid);
		minBuild(node * 2 + 1, mid + 1, e);
		minTree[node] = nodes[minTree[node * 2]] <= nodes[minTree[node * 2 + 1]] ? minTree[node * 2] : minTree[node * 2 + 1];
	}
}

void sumBuild(ll node, ll s, ll e) {
	if (s == e) sumTree[node] = nodes[s];
	else {
		ll mid = (s + e) / 2;
		sumBuild(node * 2, s, mid);
		sumBuild(node * 2 + 1, mid + 1, e);
		sumTree[node] = sumTree[node * 2] + sumTree[node * 2 + 1];
	}
}

ll getIndex(ll node, ll s, ll e, ll L, ll R) {
	if (R < s || e < L) return -1;
	if (L <= s && e <= R) return minTree[node];
	ll mid = (s + e) / 2;
	ll left = getIndex(node * 2, s, mid, L, R);
	ll right = getIndex(node * 2 + 1, mid + 1, e, L, R);

	if (left == -1) return right;
	if (right == -1) return left;
	return nodes[left] <= nodes[right] ? left : right;
}

ll sumQuery(ll node, ll s, ll e, ll L, ll R) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return sumTree[node];
	ll mid = (s + e) / 2;
	ll left = sumQuery(node * 2, s, mid, L, R);
	ll right = sumQuery(node * 2 + 1, mid + 1, e, L, R);

	return left + right;
}

ll minQuery(ll s, ll e) {
	if (s > e) return 0;
	ll min_index = getIndex(1, 0, n - 1, s, e);
	ll all = nodes[min_index] * sumQuery(1, 0, n - 1, s, e);
	ll left = minQuery(s, min_index - 1);
	ll right = minQuery(min_index + 1, e);
	return max({ all, left, right });
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (ll i = 0; i < n; i++) cin >> nodes[i];
	minBuild(1, 0, n - 1);
	sumBuild(1, 0, n - 1);
	cout << minQuery(0, n - 1);
}