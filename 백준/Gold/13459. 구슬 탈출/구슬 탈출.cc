#include<iostream>
#include<queue>
using namespace std;

int n, m;
string lst[10];
bool v[10][10][10][10];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct Pos {
	int bx, by, rx, ry, t;
};
Pos start;

void print(int bx, int by, int rx, int ry) {
	cout << bx<< " " << by << " " << rx << " " << ry << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (bx == i && by == j) cout << "B";
			else if (rx == i && ry == j) cout << "R";
			else cout << lst[i][j];
		}
		cout << "\n";
	}
}

int bfs() {
	queue<Pos> q;
	q.push(start);
	v[start.bx][start.by][start.rx][start.ry] = 1;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cbx = pos.bx, cby = pos.by, crx = pos.rx, cry = pos.ry, ct = pos.t;
		if (ct == 10) continue;

		for (int i = 0; i < 4;++i) {
			if (i == 0) {
				bool bf = false, rf = false;
				int nbx = cbx + dx[i], nrx = crx + dx[i];
				if (nbx > nrx) {
					while (lst[nbx][cby] != '#') {
						if (lst[nbx][cby] == 'O') {
							bf = true;
							nbx = -1;
							break;
						}
						nbx += dx[i];
					}
					nbx -= dx[i];

					while (lst[nrx][cry] != '#' && (nrx != nbx || cby != cry)) {
						if (lst[nrx][cry] == 'O') {
							rf = true;
							nrx = -1;
							break;
						}
						nrx += dx[i];
					}
					nrx -= dx[i];
				}
				else {
					while (lst[nrx][cry] != '#') {
						if (lst[nrx][cry] == 'O') {
							rf = true;
							nrx = -1;
							break;
						}
						nrx += dx[i];
					}
					nrx -= dx[i];

					while (lst[nbx][cby] != '#' && (nrx != nbx || cby != cry)) {
						if (lst[nbx][cby] == 'O') {
							bf = true;
							nbx = -1;
							break;
						}
						nbx += dx[i];
					}
					nbx -= dx[i];
				}

				if (bf) continue;
				else if (rf) return 1;

				if (v[nbx][cby][nrx][cry]) continue;
				v[nbx][cby][nrx][cry] = true;
				q.push({ nbx, cby, nrx, cry, ct + 1 });
				//print(nbx, cby, nrx, cry);
			}
			else if (i == 1) {
				bool bf = false, rf = false;
				int nbx = cbx + dx[i], nrx = crx + dx[i];
				if (nbx <= nrx) {
					while (lst[nbx][cby] != '#') {
						if (lst[nbx][cby] == 'O') {
							bf = true;
							nbx = -1;
							break;
						}
						nbx += dx[i];
					}
					nbx -= dx[i];

					while (lst[nrx][cry] != '#' && (nrx != nbx || cby != cry)) {
						if (lst[nrx][cry] == 'O') {
							rf = true;
							nrx = -1;
							break;
						}
						nrx += dx[i];
					}
					nrx -= dx[i];
				}
				else {
					while (lst[nrx][cry] != '#') {
						if (lst[nrx][cry] == 'O') {
							rf = true;
							nrx = -1;
							break;
						}
						nrx += dx[i];
					}
					nrx -= dx[i];

					while (lst[nbx][cby] != '#' && (nrx != nbx || cby != cry)) {
						if (lst[nbx][cby] == 'O') {
							bf = true;
							nbx = -1;
							break;
						}
						nbx += dx[i];
					}
					nbx -= dx[i];
				}

				if (bf) continue;
				else if (rf) return 1;

				if (v[nbx][cby][nrx][cry]) continue;
				v[nbx][cby][nrx][cry] = true;
				q.push({ nbx, cby, nrx, cry, ct + 1 });
				//print(nbx, cby, nrx, cry);
			}
			else if (i == 2) {
				bool bf = false, rf = false;
				int nby = cby + dy[i], nry = cry + dy[i];
				if (nby > nry) {
					while (lst[cbx][nby] != '#') {
						if (lst[cbx][nby] == 'O') {
							bf = true;
							nby = -1;
							break;
						}
						nby += dy[i];
					}
					nby -= dy[i];

					while (lst[crx][nry] != '#' && (nry != nby || cbx != crx)) {
						if (lst[crx][nry] == 'O') {
							rf = true;
							nry = -1;
							break;
						}
						nry += dy[i];
					}
					nry -= dy[i];
				}
				else {
					while (lst[crx][nry] != '#') {
						if (lst[crx][nry] == 'O') {
							rf = true;
							nry = -1;
							break;
						}
						nry += dy[i];
					}
					nry -= dy[i];

					while (lst[cbx][nby] != '#' && (crx != cbx || nby != nry)) {
						if (lst[cbx][nby] == 'O') {
							bf = true;
							nby = -1;
							break;
						}
						nby += dy[i];
					}
					nby -= dy[i];
				}

				if (bf) continue;
				else if (rf) return 1;

				if (v[cbx][nby][crx][nry]) continue;
				v[cbx][nby][crx][nry] = true;
				q.push({ cbx, nby, crx, nry, ct + 1 });
				//print(cbx, nby, crx, nry);
			}
			else if (i == 3) {
				bool bf = false, rf = false;
				int nby = cby + dy[i], nry = cry + dy[i];
				if (nby <= nry) {
					while (lst[cbx][nby] != '#') {
						if (lst[cbx][nby] == 'O') {
							bf = true;
							nby = -1;
							break;
						}
						nby += dy[i];
					}
					nby -= dy[i];

					while (lst[crx][nry] != '#' && (nry != nby || cbx != crx)) {
						if (lst[crx][nry] == 'O') {
							rf = true;
							nry = -1;
							break;
						}
						nry += dy[i];
					}
					nry -= dy[i];
				}
				else {
					while (lst[crx][nry] != '#') {
						if (lst[crx][nry] == 'O') {
							rf = true;
							nry = -1;
							break;
						}
						nry += dy[i];
					}
					nry -= dy[i];

					while (lst[cbx][nby] != '#' && (crx != cbx || nby != nry)) {
						if (lst[cbx][nby] == 'O') {
							bf = true;
							nby = -1;
							break;
						}
						nby += dy[i];
					}
					nby -= dy[i];
				}

				if (bf) continue;
				else if (rf) return 1;

				if (v[cbx][nby][crx][nry]) continue;
				v[cbx][nby][crx][nry] = true;
				q.push({ cbx, nby, crx, nry, ct + 1 });
				//print(cbx, nby, crx, nry);
			}
		}
	}
	return 0;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> lst[i];
		for (int j = 0; j < m; ++j) {
			if (lst[i][j] == 'B') {
				start.bx = i, start.by = j;
				lst[i][j] = '.';
			}
			else if (lst[i][j] == 'R') {
				start.rx = i, start.ry = j;
				lst[i][j] = '.';
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	cout << bfs();
}