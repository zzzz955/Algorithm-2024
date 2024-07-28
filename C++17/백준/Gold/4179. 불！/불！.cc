#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int r, c;
vector<string> lst;

struct pos {
	int x, y, j, t;
};

int bfs() {
	deque<pos> q;
	vector<vector<int>> v(r, vector<int>(c, 0));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (lst[i][j] == 'J') {
				q.push_front({ i, j, 1, 1 });
				v[i][j] = 1;
			}
			if (lst[i][j] == 'F') {
				q.push_back({ i, j, 0, 0 });
				v[i][j] = 2;
			}
		}
	}

	while (!q.empty()) {
		pos now = q.front();
		q.pop_front();
		int cx = now.x, cy = now.y, jf = now.j, time = now.t;
		if (cx == 0 || cx == r - 1 || cy == 0 || cy == c - 1) {
			if (v[cx][cy] == 1) return time;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (jf && 0 <= nx && nx < r && 0 <= ny && ny < c && lst[nx][ny] != '#' && !v[nx][ny]) {
				v[nx][ny] = 1;
				q.push_back({ nx, ny, jf, time + 1 });
			}
			if (!jf && 0 <= nx && nx < r && 0 <= ny && ny < c && lst[nx][ny] != '#' &&v[nx][ny] <= 1) {
				v[nx][ny] = 2;
				q.push_back({ nx, ny, jf, 0 });
			}
		}
	}
	return -1;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		lst.push_back(s);
	}
	int ans = bfs();
	if (ans == -1) cout << "IMPOSSIBLE";
	else cout << ans;
}