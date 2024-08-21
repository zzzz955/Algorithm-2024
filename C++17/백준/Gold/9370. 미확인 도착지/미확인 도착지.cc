#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<algorithm>

using namespace std;

int tc, n, m, t, s, g, h;

struct Pos {
	int d, node;
	bool operator<(const Pos& other) const {
		return d > other.d;
	}
};

int dijkstra(vector<vector<Pos>>& lst, int sn, int en) {
	priority_queue<Pos> pq;
	pq.push({ 0, sn });
	vector<int> dist(n + 1, INT_MAX);
	dist[sn] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cd = pos.d, cn = pos.node;
		if (dist[cn] != cd) continue;

		for (Pos cur : lst[cn]) {
			int nd = cur.d, nn = cur.node;
			if (dist[nn] > cd + nd) {
				dist[nn] = cd + nd;
				pq.push({ dist[nn], nn });
			}
		}
	}
	return dist[en];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	for (int c = 1; c <= tc; c++) {
		cin >> n >> m >> t >> s >> g >> h;
		vector<vector<Pos>> lst(n + 1);
		for (int i = 0; i < m; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			lst[a].push_back({ d, b });
			lst[b].push_back({ d, a });
		}
		vector<int> dn(t);
		for (int i = 0; i < t; i++) cin >> dn[i];
		sort(dn.begin(), dn.end());

		for (int i = 0; i < t; i++) {
			int md = dijkstra(lst, s, dn[i]);
			int wd = min(dijkstra(lst, s, g) + dijkstra(lst, g, h) + dijkstra(lst, h, dn[i]), dijkstra(lst, s, h) + dijkstra(lst, h, g) + dijkstra(lst, g, dn[i]));
			if (md == wd) cout << dn[i] << " ";
		}
		cout << "\n";
	}
}