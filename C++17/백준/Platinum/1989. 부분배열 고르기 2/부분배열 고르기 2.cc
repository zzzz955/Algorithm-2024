#include<iostream>
#define ll long long
using namespace std;

const ll MAX_N = 100000;
ll n;
ll nodes[MAX_N];
ll mllree[MAX_N * 4];
struct Res {
	ll val, l, r;
};
Res sumTree[MAX_N * 4];

void minBuild(ll node, ll s, ll e) {
	if (s == e) mllree[node] = s;
	else {
		ll mid = (s + e) / 2;
		minBuild(node * 2, s, mid);
		minBuild(node * 2 + 1, mid + 1, e);
		mllree[node] = nodes[mllree[node * 2]] <= nodes[mllree[node * 2 + 1]] ? mllree[node * 2] : mllree[node * 2 + 1];
	}
}

void sumBuild(ll node, ll s, ll e) {
	if (s == e) sumTree[node] = { nodes[s], s, e };
	else {
		ll mid = (s + e) / 2;
		sumBuild(node * 2, s, mid);
		sumBuild(node * 2 + 1, mid + 1, e);
		Res left = sumTree[node * 2];
		Res right = sumTree[node * 2 + 1];
		sumTree[node] = { left.val + right.val, left.l, right.r };
	}
}

ll getIndex(ll node, ll s, ll e, ll L, ll R) {
	if (R < s || e < L) return -1;
	if (L <= s && e <= R) return mllree[node];
	ll mid = (s + e) / 2;
	ll left = getIndex(node * 2, s, mid, L, R);
	ll right = getIndex(node * 2 + 1, mid + 1, e, L, R);
	if (left == -1) return right;
	if (right == -1) return left;
	return nodes[left] <= nodes[right] ? left : right;
}

Res sumQuery(ll node, ll s, ll e, ll L, ll R) {
	if (R < s || e < L) return {0, -1, -1};
	if (L <= s && e <= R) return {sumTree[node].val, L, R};
	ll mid = (s + e) / 2;
	Res left = sumQuery(node * 2, s, mid, L, R);
	Res right = sumQuery(node * 2 + 1, mid + 1, e, L, R);
	return { left.val + right.val, left.l != -1 ? left.l : right.l, right.r != -1 ? right.r : left.r };
}

Res minQuery(ll s, ll e) {
	if (s > e) return { 0, -1, -1 };
	ll min_index = getIndex(1, 0, n - 1, s, e);
	Res all = sumQuery(1, 0, n - 1, s, e);
	all.val *= nodes[min_index];
	Res left = minQuery(s, min_index - 1);
	Res right = minQuery(min_index + 1, e);
	if (all.val >= left.val && all.val >= right.val) return all;
	if (left.val >= all.val && left.val >= right.val) return left;
	return right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (ll i = 0; i < n; i++) cin >> nodes[i];
	minBuild(1, 0, n - 1);
	sumBuild(1, 0, n - 1);
	Res result = minQuery(0, n - 1);
	cout << result.val << "\n" << result.l + 1 << " " << result.r + 1;
}