#include<iostream>
#include<queue>

using namespace std;

int dx[] = { 1, 1, 1 };
int dy[] = { -1, 0, 1 };
int lst[6][6];
int n, m, ans = 1e9;

struct Pos {
	int x, y, d, v;
};

void bfs(int col, int dir) {
	queue<Pos> q;
	q.push({ 0, col, dir, lst[0][col]});

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y, cd = pos.d, cv = pos.v;
		if (cx == n - 1) {
			ans = min(ans, cv);
			continue;
		}
		for (int i = 0; i < 3; i++) {
			if (cd == i) continue;
			int nx = cx + dx[i], ny = cy + dy[i], nd = i;
			if (0 <= ny && ny < m) {
				int nv = cv + lst[nx][ny];
				if (nv < ans) q.push({ nx, ny, nd, nv });
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lst[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 3; j++) {
			bfs(i, j);
		}
	}
	cout << ans;
}