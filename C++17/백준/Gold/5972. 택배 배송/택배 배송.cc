#include<iostream>
#include<queue>

using namespace std;
int n, m;

struct Pos {
	int node, yeomul;
	bool operator<(const Pos& other) const {
		return yeomul > other.yeomul;
	}
};
vector<vector<Pos>> path;

int dijkstra(int start, int end) {
	priority_queue<Pos> pq;
	pq.push({ start, 0 });
	vector<int> dist(n + 1, 2e9);
	dist[start] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cn = pos.node, cd = pos.yeomul;
		if (dist[cn] != cd) continue;
		for (Pos next : path[cn]) {
			int nn = next.node, nd = next.yeomul;
			if (dist[nn] > cd + nd) {
				dist[nn] = cd + nd;
				pq.push({ nn, dist[nn] });
			}
		}
	}
	return dist[end];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	path.resize(n + 1);
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		path[a].push_back({ b, c });
		path[b].push_back({ a, c });
	}
	cout << dijkstra(1, n);
}