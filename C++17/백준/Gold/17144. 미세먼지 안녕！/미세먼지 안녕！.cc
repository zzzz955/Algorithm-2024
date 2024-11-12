#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int r, c, t;
int lst[51][51];
int dx[] = { -1, 0, 1, 0, 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1, 0, 1, 0, -1 };
int ddx[] = { 0, 0, 1, -1 };
int ddy[] = { 1, -1, 0, 0 };

struct Air {
	int x, y;
};

Air cleaner[2];

struct Dust {
	int x, y, c;
};

void input() {
	cin >> r >> c >> t;
	int idx = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> lst[i][j];
			if (lst[i][j] == -1) cleaner[idx++] = { i, j };
		}
	}
}

void spread(queue<Dust>& q) {
	while (!q.empty()) {
		Dust dust = q.front(); q.pop();
		int cx = dust.x, cy = dust.y, cc = dust.c;

		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int nx = cx + ddx[i], ny = cy + ddy[i];
			if (0 <= nx && nx < r && 0 <= ny && ny < c && lst[nx][ny] != -1) cnt++;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cx + ddx[i], ny = cy + ddy[i];
			if (0 <= nx && nx < r && 0 <= ny && ny < c && lst[nx][ny] != -1) lst[nx][ny] += cc / 5;
		}
		lst[cx][cy] -= cc / 5 * cnt;
	}
}

void print() {
	cout << "\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << lst[i][j] << " ";
		}
		cout << "\n";
	}
}

void blow() {
	int sx = cleaner[0].x, sy = cleaner[0].y;
	for (int i = 0; i < 4; i++) {
		int nx = sx + dx[i], ny = sy + dy[i];
		while (0 <= nx && nx <= cleaner[0].x && 0 <= ny && ny < c) {
			swap(lst[nx][ny], lst[sx][sy]);
			sx = nx, sy = ny;
			nx += dx[i], ny += dy[i];
			//print();
		}
	}
	lst[sx][sy + 1] = 0;

	sx = cleaner[1].x, sy = cleaner[1].y;
	for (int i = 4; i < 8; i++) {
		int nx = sx + dx[i], ny = sy + dy[i];
		while (cleaner[1].x <= nx && nx < r && 0 <= ny && ny < c) {
			swap(lst[nx][ny], lst[sx][sy]);
			sx = nx, sy = ny;
			nx += dx[i], ny += dy[i];
			//print();
		}
	}
	lst[sx][sy + 1] = 0;
}

void solution() {
	while (t--) {
		queue<Dust> q;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (lst[i][j] > 0) q.push({ i, j ,lst[i][j] });
			}
		}
		spread(q);
		blow();
	}
}

int chk() {
	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (lst[i][j] > 0) ans += lst[i][j];
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution();
	int result = chk();
	cout << result;
}