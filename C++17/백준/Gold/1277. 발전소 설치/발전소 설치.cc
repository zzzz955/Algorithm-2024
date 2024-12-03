#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;

int n, w;
double m;
struct Pos {
	int x, y;
};
struct Edge {
	int nn;
	double v;
	bool operator<(const Edge& other) const {
		return v > other.v;
	}
};
struct Node {
	int node;
	double d;
	bool operator<(const Node& other) const {
		return d > other.d;
	}
};
Pos poses[1001];
vector<Edge> lst[1001];

int dijkstra() {
	priority_queue<Node> pq;
	pq.push({ 1, 0 });
	vector<double> dist(n + 1, 2e9);
	dist[1] = 0;

	while (!pq.empty()) {
		Node node = pq.top(); pq.pop();
		int cn = node.node;
		double d = node.d;
		for (const Edge& edge : lst[cn]) {
			int nn = edge.nn;
			double v = edge.v;
			if (dist[nn] > d + v) {
				dist[nn] = d + v;
				pq.push({ nn, dist[nn] });
			}
		}
	}
	return dist[n] * 1000;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> w >> m;
	for (int i = 1; i <= n; ++i) {
		int x, y; cin >> x >> y;
		poses[i] = { x, y };
	}

	while (w--) {
		int a, b; cin >> a >> b;
		lst[a].push_back({ b, 0 });
		lst[b].push_back({ a, 0 });
	}

	for (int i = 1; i < n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			const Pos& cn = poses[i];
			const Pos& nn = poses[j];
			double dist = pow(pow(abs(cn.x - nn.x), 2) + pow(abs(cn.y - nn.y), 2), 0.5);
			if (dist > m) continue;
			lst[i].push_back({ j, dist });
			lst[j].push_back({ i, dist });
		}
	}

	cout << dijkstra();
}