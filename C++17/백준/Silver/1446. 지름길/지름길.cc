#include<iostream>
#include<queue>
#include<vector>
#define pii pair<int, int>
using namespace std;

int n, d;

struct Pos {
	int x, t;
	bool operator<(const Pos& other) const {
		return t > other.t;
	}
};
vector<pii> lst[10001];

int dijkstra() {
	vector<int> dist(d + 1, 2e9);
	dist[0] = 0;
	priority_queue<Pos> pq;
	pq.push({ 0, 0 });

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.x, ct = pos.t;
		if (ct > dist[cx]) continue;
		
		if (!lst[cx].empty()) {
			for (pii i : lst[cx]) {
				int nx = i.first, w = i.second;
				if (nx <= d && dist[nx] > ct + w) {
					dist[nx] = ct + w;
					pq.push({ nx, ct + w });
				}
			}
			
		}

		if (cx + 1 <= d && dist[cx + 1] > ct + 1) {
			dist[cx + 1] = ct + 1;
			pq.push({ cx + 1, dist[cx + 1] });
		}
	}
	return dist[d];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		lst[a].push_back({ b, c });
	}

	cout << dijkstra();
}