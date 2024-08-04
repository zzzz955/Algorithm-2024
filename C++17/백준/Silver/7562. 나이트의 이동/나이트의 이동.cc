#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int tc, n, sx, sy, dx, dy;

int dirx[] = { -1, -2, -2, -1, 1, 2, 2, 1};
int diry[] = { -2, -1, 1, 2, 2, 1, -1, -2};

struct Pos {
	int x, y, t;
};

int bfs(Pos pos) {
	queue<Pos> q;
	q.push(pos);
	vector<vector<int>> v(n, vector<int>(n, 0));
	v[pos.x][pos.y] = 1;

	while (!q.empty()) {
		Pos now = q.front();
		q.pop();
		int x = now.x, y = now.y, t = now.t;
		if (x == dx && y == dy) return t;
		for (int i = 0; i < 8; i++) {
			int nx = x + dirx[i], ny = y + diry[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n && !v[nx][ny]) {
				v[nx][ny] = 1;
				q.push({ nx, ny, t + 1 });
			}
		}
	}
}

int main() {
	cin >> tc;
	while (tc--) {
		cin >> n;
		cin >> sx >> sy >> dx >> dy;
		cout << bfs({ sx, sy, 0 }) << "\n";
	}
}