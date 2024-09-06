#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
int n, m, ans = 0;
int lst[300][300];
int chk[300][300];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

struct Pos {
	int x, y, val;
};

queue<Pos> q;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lst[i][j];
			if (lst[i][j]) q.push({ i, j, lst[i][j] });
		}
	}
}

void Union(int x, int y) {
	queue<Pos> now;
	now.push({ x, y });
	chk[x][y] = 1;

	while (!now.empty()) {
		Pos pos = now.front(); now.pop();
		int cx = pos.x, cy = pos.y;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && !chk[nx][ny] && lst[nx][ny]) {
				chk[nx][ny] = 1;
				now.push({ nx, ny });
			}
		}
	}
}

int chk_island() {
	int flag = 0;
	memset(chk, 0, sizeof(chk));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lst[i][j] && !chk[i][j]) {
				if (flag) return 2;
				flag++;
				Union(i, j);
			}
		}
	}
	return flag;
}

void solution() {
	int time = 0;
	while (1) {
		int result = chk_island();
		if (result == 2) {
			ans = time;
			return;
		}
		else if (!result) return;
		queue<Pos> temp;
		while (!q.empty()) {
			Pos pos = q.front(); q.pop();
			int cx = pos.x, cy = pos.y, cv = pos.val;
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i], ny = cy + dy[i];
				if (0 <= nx && nx < n && 0 <= ny && ny < m && !lst[nx][ny]) cv--;
			}
			temp.push({ cx, cy, cv });
		}
		while (!temp.empty()) {
			Pos pos = temp.front(); temp.pop();
			if (pos.val > 0) q.push(pos);
			else lst[pos.x][pos.y] = 0;
		}
		time++;
	}
}

int main() {
	input();
	solution();
	cout << ans;
}