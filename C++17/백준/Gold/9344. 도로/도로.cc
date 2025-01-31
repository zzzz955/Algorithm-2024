#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t, n, m, p, q;
int nodes[10001];
struct Edge {
	int cn, nn, w;
	bool operator<(const Edge& other) const {
		return w < other.w;
	}
};

int Find(int a) {
	if (nodes[a] == a) return a;
	return nodes[a] = Find(nodes[a]);
}

bool Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);
	if (A == B) return false;
	nodes[B] = A;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m >> p >> q;
		if (p > q) swap(p, q);
		for (int i = 1; i <= n; ++i) nodes[i] = i;
		vector<Edge> edges(n + 1);
		while (m--) {
			int a, b, c; cin >> a >> b >> c;
			if (a > b) swap(a, b);
			edges.push_back({ a, b, c });
		}
		sort(edges.begin(), edges.end());

		int cnt = 0;
		bool flag = 0;
		for (const Edge& edge : edges) {
			if (Union(edge.cn, edge.nn)) {
				cnt++;
				if (edge.cn == p && edge.nn == q) flag = 1;
			}
			if (cnt == n - 1) break;
		}

		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
}