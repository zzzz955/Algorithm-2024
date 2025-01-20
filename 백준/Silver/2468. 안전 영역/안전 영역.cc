#include<iostream>
#include<set>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

int n;
int lst[100][100];
bool v[100][100];
set<int> H;
struct Pos {
	int x, y;
};
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void bfs(int sx, int sy, int h) {
	queue<Pos> q;
	q.push({ sx, sy });
	v[sx][sy] = 1;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n && lst[nx][ny] >= h && !v[nx][ny]) {
				v[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> lst[i][j];
			H.insert(lst[i][j]);
		}
	}

	int ans = 1;
	for (int h : H) {
		memset(v, 0, sizeof(v));
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (lst[i][j] >= h && !v[i][j]) {
					cnt++;
					bfs(i, j, h);
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}