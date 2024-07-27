#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int m, n;
vector<string> lst;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

struct pos {
	int wall, x, y;
};

struct cmp {
	bool operator()(pos left, pos right) {
		if (left.wall > right.wall) return true;
		if (left.wall < right.wall) return false;
		return false;
	}
};

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		lst.push_back(s);
	}
	priority_queue<pos, vector<pos>, cmp> q;
	vector<vector<int>> v(n, vector<int>(m, 0));
	q.push({ 0, 0, 0 });
	v[0][0] = 1;
	int min_wall = 0;
	while (!q.empty()) {
		pos cpos = q.top();
		q.pop();
		int cw = cpos.wall, cx = cpos.x, cy = cpos.y;
		if (cx == n - 1 && cy == m - 1) {
			min_wall = cw;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny]) {
				v[nx][ny] = 1;
				if (lst[nx][ny] == '1') {
					cw++;
					q.push({ cw, nx, ny });
					cw--;
				}
				else {
					q.push({ cw, nx, ny });
				}
			}
		}
	}
	cout << min_wall;
}