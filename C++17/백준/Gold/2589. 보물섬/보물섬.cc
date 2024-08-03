#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, max_time = 0;
vector<string> lst;

int dx[] = { 0, 0, 1 ,-1 };
int dy[] = { 1, -1, 0, 0 };

struct Pos {
	int x, y, t;
};

void bfs(Pos pos) {
	queue<Pos> q;
	q.push(pos);
	vector<vector<int>> v(n, vector<int>(m, 0));
	v[pos.x][pos.y] = 1;

	while (!q.empty()) {
		Pos now = q.front();
		q.pop();
		int x = now.x, y = now.y, t = now.t;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny] && lst[nx][ny] == 'L') {
				v[nx][ny] = v[x][y] + 1;
				q.push({ nx, ny, t + 1 });
				max_time = max(max_time, t + 1);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	lst.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lst[i][j] == 'L') bfs({i, j, 0}); // 현재 위치가 
		}
	}
	cout << max_time;
}