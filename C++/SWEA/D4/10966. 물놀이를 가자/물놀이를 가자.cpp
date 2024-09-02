#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
int tc, n, m, ans;
string lst[1000];
int v[1000][1000];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

struct Pos {
	int x, y;
};
queue<Pos> q;

void init() {
	ans = 0;
	memset(v, -1, sizeof(v));
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
		for (int j = 0; j < m; j++) {
			if (lst[i][j] == 'W') {
				q.push({ i, j });
				v[i][j] = 0;
			}
		}
	}
}

void bfs() {
	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && v[nx][ny] == -1 && lst[nx][ny] == 'L') {
				v[nx][ny] = v[cx][cy] + 1;
				q.push({ nx, ny });
				ans += v[nx][ny];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	for (int c = 1; c <= tc; c++) {
		init();
		input();
		bfs();
		cout << "#" << c << " " << ans << "\n";
	}	
}