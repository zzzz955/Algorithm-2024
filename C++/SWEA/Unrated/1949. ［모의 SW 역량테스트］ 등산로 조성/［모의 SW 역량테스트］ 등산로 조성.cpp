#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int tc, n, k, ans, max_val;
int lst[8][8];
int v[8][8];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int cnt;

struct Pos {
	int x, y, f;
};

void init() {
	cnt = 0;
	ans = 0;
	max_val = 0;
}

void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> lst[i][j];
			max_val = max(max_val, lst[i][j]);
		}
	}
}

void dfs(int x, int y, int f) {
	if (ans < cnt) ans = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n && !v[nx][ny]) {
			if (lst[nx][ny] < lst[x][y]) {
				v[nx][ny] = 1;
				cnt++;
				dfs(nx, ny, f);
				cnt--;
				v[nx][ny] = 0;
			}
			else {
				if (!f) {
					for (int j = 1; j <= k; j++) {
						if (lst[nx][ny] - j < lst[x][y]) {
							v[nx][ny] = 1;
							lst[nx][ny] -= j;
							cnt++;
							dfs(nx, ny, f + 1);
							lst[nx][ny] += j;
							cnt--;
							v[nx][ny] = 0;
						}
					}
				}
			}
		}
	}
}

void solution() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (lst[i][j] == max_val) {
				cnt = 1;
				memset(v, 0, sizeof(v));
				v[i][j] = 1;
				dfs(i, j, 0);
			}
		}
	}
}

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		init();
		input();
		solution();
		cout << "#" << t << " " << ans << "\n";
	}
}