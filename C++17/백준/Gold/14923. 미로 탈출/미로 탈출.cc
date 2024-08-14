#include <iostream>
#include <queue>

using namespace std;

int miro[1001][1001];
int v[1001][1001][2] = { 0, };
int n, m, hx, hy, ex, ey;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

struct Pos {
	int x, y, time, wall;
};

int bfs() {
	queue<Pos> q;
	q.push({ hx - 1, hy - 1, 0 });
	v[hx][hy][0] = 1;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y, ct = pos.time, cw = pos.wall;
		if (cx == ex - 1 && cy == ey - 1) return ct;

		if (cw) {
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i], ny = cy + dy[i], nt = ct + 1;
				if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny][1]) {
					if (miro[nx][ny]) continue;
					v[nx][ny][1] = 1;
					q.push({ nx, ny, nt, cw });
				}
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i], ny = cy + dy[i], nt = ct + 1;
				if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny][0]) {
					if (miro[nx][ny] && !v[nx][ny][1]) {
						v[nx][ny][1] = 1;
						q.push({ nx, ny, nt, cw + 1 });
					}
					if (!miro[nx][ny]) {
						v[nx][ny][0] = 1;
						q.push({ nx, ny, nt, cw });
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	cin >> n >> m >> hx >> hy >> ex >> ey;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> miro[i][j];
		}
	}
	cout << bfs();
} 