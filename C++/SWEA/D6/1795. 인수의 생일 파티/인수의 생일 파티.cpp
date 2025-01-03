#include<iostream>
#include<queue>
using namespace std;

int T, N, M, X, ans;

struct Edge {
	int y, c;
};

struct Pos {
	int x, d;
	bool operator<(const Pos& other) const {
		return d > other.d;
	}
};

vector<int> dijkstra(const vector<vector<Edge>>& lst) {
	priority_queue<Pos> pq;
	pq.push({ X, 0 });
	vector<int> dist(N + 1, 2e9);
	dist[X] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.x, cd = pos.d;
		if (dist[cx] < cd) continue;

		for (const Edge& nx : lst[cx]) {
			if (dist[nx.y] > cd + nx.c) {
				dist[nx.y] = cd + nx.c;
				pq.push({ nx.y, dist[nx.y] });
			}
		}
	}
	return dist;
}

void solution(const vector<vector<Edge>>& asc, const vector<vector<Edge>>& desc) {
	vector<int> asc_Dist = dijkstra(asc);
	vector<int> desc_Dist = dijkstra(desc);
	for (int i = 1; i <= N; ++i) {
		ans = max(ans, asc_Dist[i] + desc_Dist[i]);
	}
}

int main() {
	cin >> T;
	for (int c = 1; c <= T; ++c) {
		cin >> N >> M >> X;
		vector<vector<Edge>> asc(N + 1);
		vector<vector<Edge>> desc(N + 1);
		ans = 0;
		while (M--) {
			int x, y, c; cin >> x >> y >> c;
			asc[x].push_back({ y, c });
			desc[y].push_back({ x, c });
		}
		solution(asc, desc);
		cout << "#" << c << " " << ans << "\n";
	}
}