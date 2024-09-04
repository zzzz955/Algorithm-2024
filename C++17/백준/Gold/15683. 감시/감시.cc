#include<iostream>
#include<vector>

using namespace std;

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

int n, m, k, ans = 1e9;
int lst[8][8];

struct CCTV {
	int x, y;
	vector<int> look;
};

CCTV cctv[8];

void simul(vector<int>& dirs, int flag) {
	for (int i = 0; i < k; i++) {
		CCTV tv = cctv[i];
		int dir = dirs[i];
		int sx = tv.x, sy = tv.y;
		vector<int>& look = tv.look;
		if (flag) {
			for (int i = 0; i < look.size(); i++) {
				int nd = (dir + look[i]) % 4;
				int nx = sx + dx[nd], ny = sy + dy[nd];
				while (0 <= nx && nx < n && 0 <= ny && ny < m && lst[nx][ny] != 6) {
					if (!lst[nx][ny]) lst[nx][ny] = -1;
					nx += dx[nd];
					ny += dy[nd];
				}
			}
		}
		else {
			for (int i = look.size() - 1; i >= 0; i--) {
				int nd = (dir + look[i]) % 4;
				int nx = sx + dx[nd], ny = sy + dy[nd], ex = sx, ey = sy, flag = 0;
				while (0 <= nx && nx < n && 0 <= ny && ny < m && lst[nx][ny] != 6) {
					ex = nx;
					ey = ny;
					nx += dx[nd];
					ny += dy[nd];
				}
				while (ex != sx || ey != sy) {
					if (lst[ex][ey] == -1) lst[ex][ey] = 0;
					ex -= dx[nd];
					ey -= dy[nd];
				}
			}
		}
	}
}

int chk() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lst[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

void bt(int level, vector<int>& dirs) {
	if (level == k) {
		simul(dirs, 1);
		ans = min(ans, chk());
		simul(dirs, 0);
		return;
	}

	for (int i = 0; i < 4; i++) {
		dirs.push_back(i);
		bt(level + 1, dirs);
		dirs.pop_back();
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lst[i][j];
			if (0 < lst[i][j]) {
				if (lst[i][j] == 6) continue;
				cctv[k].x = i, cctv[k].y = j;
				if (lst[i][j] == 1) cctv[k].look.push_back(0);
				else if (lst[i][j] == 2) {
					cctv[k].look.push_back(0);
					cctv[k].look.push_back(2);
				}
				else if (lst[i][j] == 3) {
					cctv[k].look.push_back(0);
					cctv[k].look.push_back(1);
				}
				else if (lst[i][j] == 4) {
					cctv[k].look.push_back(0);
					cctv[k].look.push_back(1);
					cctv[k].look.push_back(2);
				}
				else {
					cctv[k].look.push_back(0);
					cctv[k].look.push_back(1);
					cctv[k].look.push_back(2);
					cctv[k].look.push_back(3);
				}
				k++;
			}
		}
	}
	vector<int> dirs;
	bt(0, dirs);
	cout << ans;
}