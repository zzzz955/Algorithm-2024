#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m, r, ans;
int t[101];
struct Edge {
	int nn, w;
};
vector<Edge> edges[101];
struct Cur {
	int cn, d;
	bool operator<(const Cur& other) const {
		return d > other.d;
	}
};

void dijkstra(int sn) {
	priority_queue<Cur> pq;
	pq.push({ sn, 0 });
	vector<int> dist(n + 1, 2e9);
	dist[sn] = 0;

	while (!pq.empty()) {
		Cur cur = pq.top(); pq.pop();
		int cn = cur.cn, d = cur.d;

		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn, nd = d + edge.w;
			if (nd > m) continue;
			if (dist[nn] > nd) {
				dist[nn] = nd;
				pq.push({ nn, nd });
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= n; ++i) if (dist[i] != 2e9) sum += t[i];
	ans = max(ans, sum);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;
	for (int i = 1; i <= n; ++i) cin >> t[i];
	while (r--) {
		int a, b, c; cin >> a >> b >> c;
		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}
	for (int i = 1; i <= n; ++i) dijkstra(i);
	cout << ans;
}