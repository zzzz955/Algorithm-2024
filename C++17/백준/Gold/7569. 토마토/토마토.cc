#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { 0, 0, 0, 0, 1, -1 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 1, -1, 0, 0, 0, 0 };

int n, m, h;
vector<vector<vector<int>>> lst;

struct pos {
	int z, y, x, time;
};

queue<pos> dq;

void bfs() {
	queue<pos> q = dq;
	while (!q.empty()) {
		pos now = q.front();
		q.pop();
		int cz = now.z, cy = now.y, cx = now.x, ctime = now.time;
		for (int i = 0; i < 6; i++) {
			int nz = cz + dz[i], ny = cy + dy[i], nx = cx + dx[i];
			if (0 <= nz && nz < h && 0 <= ny && ny < n && 0 <= nx && nx < m && lst[nz][ny][nx] == 0) {
				lst[nz][ny][nx] = ctime + 2;
				q.push({ nz, ny, nx, ctime + 2 });
			}
		}
	}
}

int main() {
	cin >> m >> n >> h;
	lst.resize(h, vector<vector<int>>(n, vector<int> (m)));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				int num;
				cin >> num;
				lst[i][j][k] = num;
				if (num == 1) dq.push({ i, j, k, 0 });
			}
		}
	}
	int flag = 0, max_val = 0;
	bfs();
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (lst[i][j][k] == 0) {
					flag = 1;
					break;
				}
				if (lst[i][j][k] > max_val) {
					max_val = lst[i][j][k];
				}
			}
		}
	}
	if (flag) cout << -1;
	else cout << max_val / 2;
}