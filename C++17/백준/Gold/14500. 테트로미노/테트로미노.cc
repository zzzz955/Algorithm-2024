#include<iostream>
#include<algorithm>
using namespace std;

int n, m, ans;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int lst[500][500];
int v[500][500];
int h[8];

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lst[i][j];
		}
	}
}

void bt(int level, int sx, int sy, int sum) {
	if (level == 4) {
		ans = max(ans, sum);
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int nx = sx + dx[i], ny = sy + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny]) {
			v[nx][ny] = 1;
			bt(level + 1, nx, ny, sum + lst[nx][ny]);
			v[nx][ny] = 0;
		}
	}
}

void chk(int sx, int sy) {
	h[0] = lst[sx][sy] + lst[sx - 1][sy - 1] + lst[sx - 1][sy] + lst[sx - 1][sy + 1];
	h[1] = lst[sx][sy] + lst[sx - 1][sy - 1] + lst[sx][sy - 1] + lst[sx + 1][sy - 1];
	h[2] = lst[sx][sy] + lst[sx + 1][sy - 1] + lst[sx + 1][sy] + lst[sx + 1][sy + 1];
	h[3] = lst[sx][sy] + lst[sx - 1][sy + 1] + lst[sx][sy + 1] + lst[sx + 1][sy + 1];
	h[4] = lst[sx][sy] + lst[sx][sy - 1] + lst[sx - 1][sy] + lst[sx][sy + 1];
	h[5] = lst[sx][sy] + lst[sx][sy - 1] + lst[sx - 1][sy] + lst[sx + 1][sy];
	h[6] = lst[sx][sy] + lst[sx][sy - 1] + lst[sx + 1][sy] + lst[sx][sy + 1];
	h[7] = lst[sx][sy] + lst[sx][sy + 1] + lst[sx - 1][sy] + lst[sx + 1][sy];
	ans = max(ans, *max_element(h, h + 8));
}

void solution() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			v[i][j] = 1;
			bt(1, i, j, lst[i][j]);
			v[i][j] = 0;
			if (i >= 1 && j >= 1 && i < n - 1 && j < m - 1) chk(i, j);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution();	
	cout << ans;
}