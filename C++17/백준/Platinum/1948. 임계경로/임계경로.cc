#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n, m;
int cnt[10001] = { 0, };
int dist[10001] = { 0, };
int v[10001] = { 0, };
int s, e;

struct Edge {
	int node, w;
};

vector<vector<Edge>> path, rev_path;

void input() {
	cin >> n >> m;
	path.resize(n + 1);
	rev_path.resize(n + 1);
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		path[a].push_back({ b, c });
		rev_path[b].push_back({ a, c });
		cnt[b]++;
	}
	cin >> s >> e;
}

void solution() {
	queue<int> q; q.push(s);
	while (!q.empty()) {
		int cn = q.front(); q.pop();
		for (Edge edge : path[cn]) {
			int nn = edge.node, nw = edge.w;
			if (dist[nn] < dist[cn] + nw) dist[nn] = dist[cn] + nw;
			if (--cnt[nn] == 0) q.push(nn);
		}
	}
	cout << dist[e] << "\n";
}

void rev() {
	int back_cnt = 0;
	queue<int> q; q.push(e);
	while (!q.empty()) {
		int cn = q.front(); q.pop();
		for (Edge edge : rev_path[cn]) {
			int pn = edge.node, nw = edge.w;
			if (dist[pn] + nw == dist[cn]) {
				back_cnt++;
				if (!v[pn]) {
					v[pn] = 1;
					q.push(pn);
				}
			}
		}
	}
	cout << back_cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution();
	rev();
}