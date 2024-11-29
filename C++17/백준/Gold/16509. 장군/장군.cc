#include<iostream>
#include<queue>
using namespace std;

struct Pos {
	int x, y, t;
};

Pos King;
Pos Elep;

const int r = 10;
const int c = 9;

//int dx[] = { -3, -3, -2, 2, 3, 3, 2, -2 };
//int dy[] = { -2, 2, 3, 3, 2, -2, -3, -3 };

int dx[8][3] = {
	{-1, -1, -1},
	{-1, -1, -1},
	{0, -1, -1},
	{0, 1, 1},
	{1, 1, 1},
	{1, 1, 1},
	{0, 1, 1},
	{0, -1, -1}
};

int dy[8][3] = {
	{0, -1, -1},
	{0, 1, 1},
	{1, 1, 1},
	{1, 1, 1},
	{0, 1, 1},
	{0, -1, -1},
	{-1, -1, -1},
	{-1, -1, -1}
};

int map[r][c];
int v[r][c];

int bfs() {
	queue<Pos> q;
	q.push({ Elep.x, Elep.y, 0 });
	v[Elep.x][Elep.y] = 1;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y, ct = pos.t;
		if (map[cx][cy]) return ct;

		for (int i = 0; i < 8; ++i) {
			int nx = cx, ny = cy, nt = ct + 1, flag = 1;
			for (int j = 0; j < 3; ++j) {
				nx += dx[i][j], ny += dy[i][j];
				if (0 <= nx && nx < r && 0 <= ny && ny < c) {
					if (map[nx][ny] && j < 2) {
						flag = 0;
						break;
					}
				}
				else {
					flag = 0;
					break;
				}
			}
			if (flag) {
				v[nx][ny] = 1;
				q.push({ nx, ny, nt });
			}
		}
	}
	return -1;
}

int main() {
	cin >> Elep.x >> Elep.y >> King.x >> King.y;
	map[King.x][King.y] = 1;
	cout << bfs();
}