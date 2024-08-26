#include<iostream>
#include<queue>

using namespace std;

string lst[50];
int v[50][50] = { 0, };
int r, c, sx, sy, ex, ey;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

struct Pos {
	int x, y;
	char z;
};

queue<Pos> q;

int bfs() {
	q.push({ sx, sy, 'S' });
	v[sx][sy] = 1;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y, cz = pos.z;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < r && 0 <= ny && ny < c && !v[nx][ny] && lst[nx][ny] != '*' && lst[nx][ny] != 'X') {
				if (cz == '*' && lst[nx][ny] == '.') {
					lst[nx][ny] = '*';
					q.push({ nx, ny, '*' });
				}
				else if (cz == 'S' && lst[nx][ny] == 'D') return v[cx][cy];
				else if (cz == 'S' && lst[nx][ny] != '*') {
					v[nx][ny] = v[cx][cy] + 1;
					q.push({ nx, ny, 'S' });
				}
			}
		}
	}
	return -1;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> lst[i];
		for (int j = 0; j < c; j++) {
			if (lst[i][j] == 'S') sx = i, sy = j;
			else if (lst[i][j] == 'D') ex = i, ey = j;
			else if (lst[i][j] == '*') q.push({ i, j, '*' });
		}
	}
	int ans = bfs();
	if (ans == -1) cout << "KAKTUS";
	else cout << ans;
}