#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int n, far_node, max_dist;
int v[100001];

struct Edge {
	int c, d;
};

vector<Edge> edges[100001];

void dfs(int node, int dist) {
	if (max_dist < dist) {
		max_dist = dist;
		far_node = node;
	}

	for (Edge edge : edges[node]) {
		int c = edge.c, d = edge.d;
		if (v[c]) continue;
		v[c] = 1;
		dfs(c, dist + d);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int cur; cin >> cur;
		while (1) {
			int next; cin >> next;
			if (next == -1) break;
			int w; cin >> w;
			edges[cur].push_back({ next, w });
		}
	}
	v[1] = 1;
	dfs(1, 0);

	max_dist = 0;
	memset(v, 0, sizeof(v));
	v[far_node] = 1;
	dfs(far_node, 0);

	cout << max_dist;
}