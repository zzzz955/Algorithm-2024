#include<iostream>
#include<vector>

using namespace std;

const int MAX_N = 100001;
int n, m;
int tree[MAX_N * 4];

vector<int> lst[MAX_N];
int it[MAX_N];
int ot[MAX_N];
int timer;

void dfs(int boss) {
	it[boss] = ++timer;
	for (int child : lst[boss]) dfs(child);
	ot[boss] = timer;
}

void update(int node, int s, int e, int idx, int val) {
	if (s == e) tree[node] += val;
	else {
		int mid = (s + e) / 2;
		if (idx <= mid) update(node * 2, s, mid, idx, val);
		else update(node * 2 + 1, mid + 1, e, idx, val);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

int query(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return 0;
	if (L <= s && e <= R) return tree[node];
	int mid = (s + e) / 2;
	int left = query(node * 2, s, mid, L, R);
	int right = query(node * 2 + 1, mid + 1, e, L, R);
	return left + right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int trash;
	cin >> n >> m >> trash;
	for (int i = 2; i <= n; i++) {
		int boss; cin >> boss;
		lst[boss].push_back(i);
	}

	dfs(1);

	while (m--) {
		int order, idx; cin >> order >> idx;
		if (order == 1) {
			int val; cin >> val;
			update(1, 1, n, it[idx], val);
		}
		else cout << query(1, 1, n, it[idx], ot[idx]) << "\n";
	}
}