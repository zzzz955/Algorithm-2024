#include<iostream>
#include<queue>
#include<cmath>
#include<unordered_map>
using namespace std;

int lst[3][3];
unordered_map<int, bool> v;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct Pos {
	int x, y, b, t;
	bool operator<(const Pos& other) const {
		return t > other.t;
	}
};

int bfs(const Pos& start) {
	priority_queue<Pos> q;
	q.push(start);
	v[start.b] = 1;
	int target = 87654321;

	while (!q.empty()) {
		Pos pos = q.top(); q.pop();
		int cx = pos.x, cy = pos.y, cb = pos.b, ct = pos.t;
		if (cb == target) return ct;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i], nt = ct + 1;
			if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
				int nf = cb / (int)pow(10, 3 * nx + ny) % 10;
				int nb = cb - (int)pow(10, 3 * nx + ny) * nf + (int)pow(10, 3 * cx + cy) * nf;
				if (v[nb]) continue;
				v[nb] = 1;
				q.push({ nx, ny, nb, nt });
			}
		}
	}
	return -1;
}

int main() {
	Pos pos;
	int bits = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> lst[i][j];
			if (!lst[i][j]) {
				pos = { i, j, 0, 0 };
				continue;
			}
			bits += pow(10, 3 * i + j) * lst[i][j];
		}
	}
	pos.b = bits;
	cout << bfs(pos);
}