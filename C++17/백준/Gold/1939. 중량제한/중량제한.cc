#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m;
int nodes[10001];
bool v[10001];
struct Edge {
	int nn, w;
};
struct Cur {
	int cn, mw;
	bool operator<(const Cur& other) const {
		return mw < other.mw;
	}
};
vector<Edge> edges[10001];

int bfs() {
	int sn, dn; cin >> sn >> dn;
	priority_queue<Cur> pq;
	pq.push({ sn, 2000000000 });
	vector<int> dist(n + 1, 0);

	while (!pq.empty()) {
		Cur cur = pq.top(); pq.pop();
		int cn = cur.cn, mw = cur.mw;
		dist[cn] = max(dist[cn], mw);
		if (cn == dn) break;
		if (v[cn]) continue;
		v[cn] = 1;

		for (const Edge& edge : edges[cn]) {
			int nn = edge.nn, nw = min(mw, edge.w);
			pq.push({ nn, nw });
		}
	}
	return dist[dn];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}
	cout << bfs();
}
