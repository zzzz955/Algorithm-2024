#include<iostream>
#include<queue>
#include<vector>
#include<climits>

using namespace std;

int n, e, v1, v2;
vector<vector<pair<int, int>>> lst;

int dijkstra(int sn, int dn) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, sn });
	vector<int> dist(n + 1, INT_MAX);
	dist[sn] = 0;

	while (!pq.empty()) {
		pair<int, int> cur = pq.top(); pq.pop();
		int cd = cur.first, cn = cur.second;
		if (dist[cn] != cd) continue;
		for (pair<int, int> next : lst[cn]) {
			int nd = next.first, nn = next.second;
			if (dist[nn] > cd + nd) {
				dist[nn] = cd + nd;
				pq.push({ dist[nn], nn });
			}
		}
	}
	return dist[dn];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> e;
	lst.resize(n + 1);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		lst[a].push_back({ c, b });
		lst[b].push_back({ c, a });
	}
	cin >> v1 >> v2;
	int d1 = dijkstra(1, v1);
	int d2 = dijkstra(v1, v2);
	int d3 = dijkstra(v2, n);

	int d4 = dijkstra(1, v2);
	int d5 = dijkstra(v2, v1);
	int d6 = dijkstra(v1, n);

	int ans1 = INT_MAX, ans2 = INT_MAX;
	if (d1 != INT_MAX && d2 != INT_MAX && d3 != INT_MAX) ans1 = d1 + d2 + d3;
	if (d4 != INT_MAX && d5 != INT_MAX && d6 != INT_MAX) ans2 = d4 + d5 + d6;
	int result = min(ans1, ans2);
	if (result != INT_MAX) cout << result;
	else cout << -1;
}