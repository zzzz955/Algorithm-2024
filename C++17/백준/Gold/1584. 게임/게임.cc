#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n, m;
int lst[501][501];
bool v[501][501];
int dx[] = { 1, 0, 0, -1 };
int dy[] = { 0, 1, -1, 0 };

struct Pos {
	int x, y, t;
	bool operator<(const Pos& other) const {
		return t > other.t;
	}
};

int bfs() {
	priority_queue<Pos> q;
	q.push({ 0, 0, 0 });
	v[0][0] = true;

	while (!q.empty()) {
		Pos pos = q.top(); q.pop();
		int cx = pos.x, cy = pos.y, ct = pos.t;
		if (cx == 500 && cy == 500) return ct;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < 501 && 0 <= ny && ny < 501 && lst[nx][ny] != -1 && !v[nx][ny]) {
				v[nx][ny] = true;
				if (lst[nx][ny]) q.push({ nx, ny, ct + 1 });
				else q.push({ nx, ny, ct });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		for (int i = x1; i <= x2; ++i)
			for (int j = y1; j <= y2; ++j)
				lst[i][j] = 1;
	}

	cin >> m;
	while (m--) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		for (int i = x1; i <= x2; ++i)
			for (int j = y1; j <= y2; ++j)
				lst[i][j] = -1;
	}
	cout << bfs();
}