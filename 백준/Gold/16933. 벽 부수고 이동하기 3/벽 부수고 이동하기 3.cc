#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m, k;
string lst[1000];
struct Pos {
	int x, y, t, k, w;
	bool operator < (const Pos& other) const {
		return t > other.t;
	}
};
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void print(int cx, int cy, int ct, int ck, int cw) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i == cx && j == cy) cout << '2';
			else {
				cout << lst[i][j];
			}
		}
		cout << "\n";
	}
	cout << ct << " " << ck << " " << cw << "\n";
}

int bfs() {
	priority_queue<Pos> q;
	q.push({ 0, 0, 1, 0, 0 });
	vector<vector<vector<int>>> v(n, vector<vector<int>>(m, vector<int>(k + 1, 2e9)));
	v[0][0][0] = 1;

	while (!q.empty()) {
		Pos pos = q.top(); q.pop();
		int cx = pos.x, cy = pos.y, ct = pos.t, ck = pos.k, cw = pos.w;
		//print(cx, cy, ct, ck, cw);
		if (cx == n - 1 && cy == m - 1) return ct;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i], nt = ct + 1, nk = ck + 1, nw = cw ^ 1;
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (!cw) {
					if (lst[nx][ny] == '1') {
						if (nk > k || v[nx][ny][nk] <= nt) continue;
						v[nx][ny][nk] = nt;
						q.push({ nx, ny, nt, nk, nw });
					}
					else {
						if (v[nx][ny][ck] <= nt) continue;
						v[nx][ny][ck] = nt;
						q.push({ nx, ny, nt, ck, nw });
					}
				}
				else {
					if (lst[nx][ny] == '1') {
						if (nk > k || v[nx][ny][nk] <= ++nt) continue;
						v[nx][ny][nk] = nt;
						q.push({ nx, ny, nt, nk, cw });
					}
					else {
						if (v[nx][ny][ck] <= nt) continue;
						v[nx][ny][ck] = nt;
						q.push({ nx, ny, nt, ck, nw });
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) cin >> lst[i];
	cout << bfs();
}