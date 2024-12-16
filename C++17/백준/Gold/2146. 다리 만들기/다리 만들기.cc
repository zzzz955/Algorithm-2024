#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int n, g, ans = 1e9;
int lst[100][100];
bool v[100][100];
bool vg[10000];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
struct Pos {
	int x, y, t;
	bool operator<(const Pos& other) const {
		return t > other.t;
	}
};

void input() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> lst[i][j];
}

void conn(int sx, int sy, int g) {
	priority_queue<Pos> q;
	q.push({ sx, sy, 0 });
	v[sx][sy] = 1;

	while (!q.empty()) {
		Pos pos = q.top(); q.pop();
		int cx = pos.x, cy = pos.y, ct = pos.t;
		if (ct >= ans) continue;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n && !v[nx][ny]) {
				v[nx][ny] = 1;
				if (lst[nx][ny] == g) q.push({ nx, ny, ct });
				else if (!lst[nx][ny]) q.push({ nx, ny, ct + 1 });
				else ans = min(ans, ct);
			}
		}
	}
}

void getDist() {
	vg[0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (vg[lst[i][j]]) continue;
			vg[lst[i][j]] = 1;
			memset(v, 0, sizeof(v));
			conn(i, j, lst[i][j]);
		}
	}
}

void floodfill(int sx, int sy, int g) {
	queue<Pos> q;
	q.push({ sx, sy });
	v[sx][sy] = 1;
	lst[sx][sy] = g;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n && !v[nx][ny] && lst[nx][ny]) {
				v[nx][ny] = 1;
				lst[nx][ny] = g;
				q.push({ nx, ny });
			}
		}
	}
}

void grouping() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (v[i][j] || !lst[i][j]) continue;
			floodfill(i, j, ++g);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	grouping();
	getDist();

	cout << ans;
}