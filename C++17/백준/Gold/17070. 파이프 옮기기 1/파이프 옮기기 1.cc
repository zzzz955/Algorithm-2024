#include<iostream>

using namespace std;

int n, ans;
int lst[16][16];
int v[16][16] = { 0, };
int dx[] = { 0, 1, 1 };
int dy[] = { 1, 1, 0 };

void dfs(int x, int y, int dir) {
	if (x == n - 1 && y == n - 1) {
		ans++;
		return;
	}
	for (int i = -1; i < 2; i++) {
		int ndir = dir + i;
		if (ndir < 0 || 2 < ndir) continue;
		int nx = x + dx[ndir], ny = y + dy[ndir];
		if (nx < n && ny < n && !v[nx][ny] && !lst[nx][ny]) {
			if (ndir == 1 && (lst[nx][ny - 1] || lst[nx - 1][ny])) continue;
			v[nx][ny] = 1;
			dfs(nx, ny, ndir);
			v[nx][ny] = 0;
		}
	}
}

int main() {
	cin >> n;
	ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> lst[i][j];
		}
	}
	v[0][0] = 1;
	v[0][1] = 1;
	dfs(0, 1, 0);
	cout << ans;
}