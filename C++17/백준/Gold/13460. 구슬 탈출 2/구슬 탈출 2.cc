#include<iostream>
#include<queue>

using namespace std;

int n, m, sx1, sy1, sx2, sy2;
string lst[10];
int v[11][11][11][11] = {0,};
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

struct Pos {
	int rx, ry, bx, by, t;
};

//void print(int cx1, int cy1, int cx2, int cy2, int time) {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (i == cx1 && j == cy1) cout << 'R';
//			else if (i == cx2 && j == cy2) cout << 'B';
//			else cout << lst[i][j];
//		}
//		cout << "\n";
//	}
//	cout << time << "\n";
//}

int bfs() {
	queue<Pos> q;
	q.push({ sx1, sy1, sx2, sy2, 0 });
	v[sx1][sy1][sx2][sy2] = 1;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int crx = pos.rx, cry = pos.ry, cbx = pos.bx, cby = pos.by, ct = pos.t;
		
		if (ct == 10) continue;
		for (int i = 0; i < 4; i++) {
			int nrx = crx, nry = cry, nbx = cbx, nby = cby, nt = ct + 1;
			int flag1 = 1, flag2 = 1;

			if ((i == 0 && cry >= cby) || (i == 1 && cry < cby) || (i == 2 && crx >= cbx) || (i == 3 && crx < cbx)) {
				while (flag1 || flag2) {
					if (flag1 && 0 <= nrx + dx[i] && nrx + dx[i] < n && 0 <= nry + dy[i] && nry + dy[i] < m && lst[nrx + dx[i]][nry + dy[i]] != '#' && (nrx + dx[i] != nbx || nry + dy[i] != nby)) {
						nrx += dx[i]; nry += dy[i];
						if (lst[nrx][nry] == 'O') {
							nrx = 10, nry = 10;
							flag1 = 0;
						}
					}
					else flag1 = 0;
					if (flag2 && 0 <= nbx + dx[i] && nbx + dx[i] < n && 0 <= nby + dy[i] && nby + dy[i] < m && lst[nbx + dx[i]][nby + dy[i]] != '#' && (nbx + dx[i] != nrx || nby + dy[i] != nry)) {
						nbx += dx[i]; nby += dy[i];
						if (lst[nbx][nby] == 'O') {
							nbx = 10, nby = 10;
							flag2 = 0;
						}
					}
					else flag2 = 0;
				}
			}
			else {
				while (flag1 || flag2) {
					if (flag2 && 0 <= nbx + dx[i] && nbx + dx[i] < n && 0 <= nby + dy[i] && nby + dy[i] < m && lst[nbx + dx[i]][nby + dy[i]] != '#' && (nbx + dx[i] != nrx || nby + dy[i] != nry)) {
						nbx += dx[i]; nby += dy[i];
						if (lst[nbx][nby] == 'O') {
							nbx = 10, nby = 10;
							flag2 = 0;
						}
					}
					else flag2 = 0;
					if (flag1 && 0 <= nrx + dx[i] && nrx + dx[i] < n && 0 <= nry + dy[i] && nry + dy[i] < m && lst[nrx + dx[i]][nry + dy[i]] != '#' && (nrx + dx[i] != nbx || nry + dy[i] != nby)) {
						nrx += dx[i]; nry += dy[i];
						if (lst[nrx][nry] == 'O') {
							nrx = 10, nry = 10;
							flag1 = 0;
						}
					}
					else flag1 = 0;
				}
			}

			if (v[nrx][nry][nbx][nby]) continue;
			if (nbx == 10 && nby == 10) continue;
			if (nrx == 10 && nry == 10) return nt;
			v[nrx][nry][nbx][nby] = 1;
			q.push({ nrx, nry, nbx, nby, nt });
			//print(nrx, nry, nbx, nby, nt);
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
		for (int j = 0; j < m; j++) {
			if (lst[i][j] == 'B') {
				sx2 = i, sy2 = j;
				lst[i][j] = '.';
			}
			else if (lst[i][j] == 'R') {
				sx1 = i, sy1 = j;
				lst[i][j] = '.';
			}
		}
	}

	cout << bfs();
}