#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 100001;
int n, m, i, j, k, last;
int nodes[N];
vector<int> tree[N * 4];

void build(int node, int s, int e) {
	if (s == e) tree[node] = { nodes[s] };
	else {
		int mid = (s + e) / 2;
		build(node * 2, s, mid);
		build(node * 2 + 1, mid + 1, e);
		vector<int>& L = tree[node * 2];
		vector<int>& R = tree[node * 2 + 1];
		tree[node].resize(L.size() + R.size());
		merge(L.begin(), L.end(), R.begin(), R.end(), tree[node].begin());
	}
}

int query(int node, int s, int e, int L, int R, int val) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) {
		auto it = upper_bound(tree[node].begin(), tree[node].end(), val);
		return tree[node].end() - it;
	}
	int mid = (s + e) / 2;
	int left = query(node * 2, s, mid, L, R, val);
	int right = query(node * 2 + 1, mid + 1, e, L, R, val);
	return left + right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> nodes[i];
	build(1, 1, n);
	
	cin >> m;
	while (m--) {
		int a, b, c;  cin >> a >> b >> c;
		i = last ^ a;
		j = last ^ b;
		k = last ^ c;
		last = query(1, 1, n, i, j, k);
		cout << last << "\n";
	}
}