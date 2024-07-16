#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int n, m;
vector<vector<int>> lst;
vector<vector<int>> ans;
vector<pair<int, int>> dist = { {1,0}, {-1,0}, {0, 1}, {0, -1} };

void bfs(queue<pair<int, int>> q) {
	ans[q.front().first][q.front().second] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < dist.size(); i++) {
			int nx = x + dist[i].first;
			int ny = y + dist[i].second;
			if (0 <= nx && nx < n && 0 <= ny && ny < m && ans[nx][ny] == -1) {
				ans[nx][ny] = ans[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	cin >> n >> m;
	lst.resize(n, vector<int>(m));
	ans.resize(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lst[i][j];
		}
	}
	queue<pair<int, int>> start;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lst[i][j] == 2) {
				start.push({ i, j });
			}
			if (lst[i][j] == 0) {
				ans[i][j] = 0;
			}
		}
	}
	bfs(start);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}