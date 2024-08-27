#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

int tc, n, w, h, ans;
int lst[15][12];
int v[12];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

struct Pos {
	int x, y, p;
};

void init() {
	ans = 1e9;
	memset(v, 0, sizeof(v));
}

void input() {
	cin >> n >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> lst[i][j];
		}
	}
}

void dfs(int level, int col, vector<vector<int>> map) {
	if (level > n) {
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] > 0) cnt++;
			}
		}
		ans = min(ans, cnt);
		return;
	}
	queue<Pos> q;
	int flag = 0;
	for (int i = 0; i < h; i++) {
		if (map[i][col] == 0) continue;
		else if (map[i][col] == 1) {
			map[i][col] = 0;
			flag = 1;
			break;
		}
		else if (map[i][col] > 1) {
			q.push({ i, col, map[i][col] });
			map[i][col] = 0;
			while (!q.empty()) {
				Pos pos = q.front(); q.pop();
				int cx = pos.x, cy = pos.y, cp = pos.p;
				for (int i = 0; i < 4; i++) {
					int nx = cx, ny = cy, np = cp - 1;
					while (np--) {
						nx += dx[i];
						ny += dy[i];
						if (nx < 0 || h <= nx || ny < 0 || w <= ny) break;
						if (map[nx][ny] == 0) continue;
						else if (map[nx][ny] == 1) map[nx][ny] = 0;
						else if (map[nx][ny] > 1) {
							q.push({ nx, ny, map[nx][ny] });
							map[nx][ny] = 0;
						}
					}
				}
			}
			for (int j = 0; j < w; j++) {
				queue<int> nums;
				int first = h, flag = 0;
				for (int i = h - 1; i >= 0; i--) {
					if (flag && map[i][j] > 0) {
						nums.push(map[i][j]);
						map[i][j] = 0;
					}
					if (!flag && map[i][j] == 0) {
						flag = 1;
						first = i;
					}
				}
				while (!nums.empty()) {
					map[first][j] = nums.front();
					nums.pop();
					first--;
				}
			}
			flag = 1;
			break;
		}
	}
	if (!flag) v[col] = 1;
	for (int i = 0; i < w; i++) {
		if (!v[i]) {
			dfs(level + 1, i, map);
			v[i] = 0;
		}
	}
}

void solution() {
	for (int i = 0; i < w; i++) {
		vector<vector<int>> map(h, vector<int>(w));
		for (int j = 0; j < h; j++) {
			for (int k = 0; k < w; k++) {
				map[j][k] = lst[j][k];
			}
		}
		dfs(1, i, map);
	}
}

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		init();
		input();
		solution();
		cout << "#" << t << " " << ans << "\n";
	}
}