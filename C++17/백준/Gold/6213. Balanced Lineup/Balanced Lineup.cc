#include<iostream>
using namespace std;

const int N = 50000;
int n, q;
int nodes[N];
int Mintree[N * 4];
int Maxtree[N * 4];
struct MM {
	int minv, maxv;
};

void build(int node, int s, int e) {
	if (s == e) {
		Mintree[node] = nodes[s];
		Maxtree[node] = nodes[s];
		return;
	}
	int mid = (s + e) / 2;
	build(node * 2, s, mid);
	build(node * 2 + 1, mid + 1, e);
	Mintree[node] = min(Mintree[node * 2], Mintree[node * 2 + 1]);
	Maxtree[node] = max(Maxtree[node * 2], Maxtree[node * 2 + 1]);
}

MM query(int node, int s, int e, int L, int R) {
	if (R < s || e < L) return { 1000001, 0 };
	if (L <= s && e <= R) return { Mintree[node], Maxtree[node] };
	int mid = (s + e) / 2;
	MM left = query(node * 2, s, mid, L, R);
	MM right = query(node * 2 + 1, mid + 1, e, L, R);
	return { min(left.minv, right.minv), max(left.maxv, right.maxv) };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 0; i < n; ++i) cin >> nodes[i];

	build(1, 0, n - 1);

	while (q--) {
		int s, e; cin >> s >> e;
		MM result = query(1, 0, n - 1, s - 1, e - 1);
		cout << result.maxv - result.minv << "\n";
	}
}