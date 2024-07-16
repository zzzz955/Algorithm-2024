#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int m, n;
vector<vector<int>> lst;
vector<pair<int, int>> dist = {
	{1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

void bfs() {
	queue<pair<int, int>> q;
	vector<vector<bool>> v(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lst[i][j] == 1) {
				q.push({ i, j });
				v[i][j] = true;
			}
		}
	}
	while (!q.empty()) {
		pair<int, int> pos = q.front();
		int x = pos.first;
		int y = pos.second;
		q.pop();

		for (const pair<int, int> dir : dist) {
			int dx = dir.first;
			int dy = dir.second;
			int nx = x + dx;
			int ny = y + dy;
			if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny] && lst[nx][ny] == 0) {
				v[nx][ny] = true;
				lst[nx][ny] = lst[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	cin >> m >> n;
	lst.resize(n, vector<int>(m));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lst[i][j];
		}
	}

	bfs();
	int max_day = 0;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lst[i][j] == 0) flag = false;
			max_day = max(max_day, lst[i][j]);
		}
	}

	if (flag) cout << max_day - 1;
	else cout << -1;
}