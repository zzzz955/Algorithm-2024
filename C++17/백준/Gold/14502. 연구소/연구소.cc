#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int n, m, min_wall = 0;
vector<vector<int>> lst;

struct pos {
	int x, y;
};

queue<pos> dq;

void bfs() {
	vector<vector<int>> v = lst;
	queue<pos> q = dq;

	while (!q.empty()) {
		pos now = q.front();
		q.pop();
		int cx = now.x, cy = now.y;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny]) {
				v[nx][ny] = 2;
				q.push({ nx, ny});
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 0) sum++;
		}
	}
	min_wall = max(min_wall, sum);
}

void wall(int x, int y, int done) {
	for (int i = x; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == x && j < y) continue;
			if (lst[i][j] == 0) {
				lst[i][j] = 1;
				done++;
				if (done == 3) bfs();
				else wall(i, j, done);
				lst[i][j] = 0;
				done--;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	lst.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			lst[i][j] = num;
			if (num == 2) dq.push({ i, j });
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lst[i][j] == 0) {
				lst[i][j] = 1;
				wall(i, j, 1);
				lst[i][j] = 0;
			}
		}
	}
	cout << min_wall;
}