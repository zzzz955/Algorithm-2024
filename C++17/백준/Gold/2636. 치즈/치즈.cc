#include<iostream>
#include<queue>
using namespace std;

int n, m, remain, last, ans;
int lst[100][100];
int v[100][100];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

struct Pos {
	int x, y;
};
queue<Pos> h;
queue<Pos> c;

void melt() {
	while (!c.empty()) {
		Pos pos = c.front(); c.pop();
		int cx = pos.x, cy = pos.y;
		lst[cx][cy] = 0;
		h.push({ cx, cy });
		remain--;
	}
}

void bfs() {
	while (!h.empty()) {
		Pos pos = h.front(); h.pop();
		int cx = pos.x, cy = pos.y;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny]) {
				v[nx][ny] = 1;
				if (!lst[nx][ny]) h.push({ nx, ny });
				else c.push({ nx, ny });
			}
		}
	}
	melt();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> lst[i][j];
			if (lst[i][j]) remain++;
		}
	}

	h.push({ 0, 0 });
	while (remain) {
		ans++;
		last = remain;
		bfs();
	}
	cout << ans << "\n" << last;
}