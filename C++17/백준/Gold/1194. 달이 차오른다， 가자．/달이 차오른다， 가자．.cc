#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

const char A = 'A';
const char a = 'a';
int n, m, sx, sy;
string lst[50];
bool v[50][50][64];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

struct Pos {
	int x, y, t, k;
};

int bfs() {
	queue<Pos> q;
	q.push({ sx, sy, 0 });
	v[sx][sy][0] = 1;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y, ct = pos.t, ck = pos.k;
		if (lst[cx][cy] == '1') return ct;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i], nt = ct + 1;
			if (0 <= nx && nx < n && 0 <= ny && ny < m && lst[nx][ny] != '#') {
				if (v[nx][ny][ck]) continue;

				if (lst[nx][ny] == '.') {
					v[nx][ny][ck] = 1;
					q.push({ nx, ny, nt, ck });
				}
				else if (lst[nx][ny] >= 'a') {
					int key = pow(2, lst[nx][ny] - a);
					if (ck & key) {
						v[nx][ny][ck] = 1;
						q.push({ nx, ny, nt, ck });
					}
					else {
						v[nx][ny][ck + key] = 1;
						q.push({ nx, ny, nt, ck + key });
					}
				}
				else if (lst[nx][ny] >= 'A') {
					int key = pow(2, lst[nx][ny] - A);
					if (ck & key) {
						v[nx][ny][ck] = 1;
						q.push({ nx, ny, nt, ck });
					}
				}
				else if (lst[nx][ny] == '1') return nt;
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> lst[i];
		for (int j = 0; j < m; ++j) {
			if (lst[i][j] == '0') {
				sx = i, sy = j;
				lst[i][j] = '.';
			}
		}
	}
	cout << bfs();
}