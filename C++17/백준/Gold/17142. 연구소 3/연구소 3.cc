#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
int n, m, length, ans = 1e9;
int lst[50][50];
int visit[50][50];
int v[10] = { 0, };

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

struct Pos {
	int x, y, d;
};

vector<Pos> virus;

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (lst[i][j] == 1) visit[i][j] = 0;
			else visit[i][j] = -1;
		}
	}
}

int bfs(vector<int>& path) {
	queue<Pos> q;
	init();
	for (int i = 0; i < m; i++) {
		Pos pos = virus[path[i]];
		q.push(pos);
		visit[pos.x][pos.y] = 0;
	}
	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y, cd = pos.d;
		if (visit[cx][cy] >= ans) return 1e9;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i], nd = cd + 1;
			if (0 <= nx && nx < n && 0 <= ny && ny < n && visit[nx][ny] == -1 && lst[nx][ny] != -1) {
				if (lst[nx][ny] == 2) visit[nx][ny] = 0;
				else visit[nx][ny] = nd;
				q.push({ nx, ny, nd });
			}
		}
	}
	int max_val = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == -1 && !lst[i][j]) return 1e9;
			else max_val = max(max_val, visit[i][j]);
		}
	}
	return max_val;
}

void dfs(int level, vector<int>& path) {
	if (level == m) {
		ans = min(ans, bfs(path));
		return;
	}

	for (int i = 0; i < length; i++) {
		if (v[i]) continue;
		if (!path.empty() && i < path[level - 1]) continue;
		v[i] = 1;
		path.push_back(i);
		dfs(level + 1, path);
		path.pop_back();
		v[i] = 0;
	}
}

int main() {
	cin >> n >> m;
	int index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> lst[i][j];
			if (lst[i][j] == 2) virus.push_back({i, j, 0});
		}
	}
	length = virus.size();
	vector<int> path;
	dfs(0, path);
	if (ans == 1e9) cout << -1;
	else cout << ans;
}