#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m, ans = 2e9;
int lst[1000][1000];
int dist[1000][1000][4];
int dx[] = { 1, 1, 1 };
int dy[] = { -1, 0, 1 };
struct Pos {
	int x, y, w, d;
	bool operator<(const Pos& other) const {
		return w > other.w;
	}
};

void dijkstra() {
	priority_queue<Pos> pq;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			for (int k = 0; k < 4; ++k)
				dist[i][j][k] = 2e9;

	for (int i = 0; i < m; ++i) {
		pq.push({ 0, i, lst[0][i], 3 });
		dist[0][i][3] = lst[0][i];
	}

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.x, cy = pos.y, cw = pos.w, cd = pos.d;
		if (dist[cx][cy][cd] > cw) continue;

		for (int i = 0; i < 3; ++i) {
			if (i == cd) continue;
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (dist[nx][ny][i] > cw + lst[nx][ny]) {
					dist[nx][ny][i] = cw + lst[nx][ny];
					pq.push({ nx, ny, dist[nx][ny][i], i});
				}
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < 3; ++j) {
			ans = min(ans, dist[n - 1][i][j]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> lst[i][j];
	dijkstra();
	cout << ans;
}