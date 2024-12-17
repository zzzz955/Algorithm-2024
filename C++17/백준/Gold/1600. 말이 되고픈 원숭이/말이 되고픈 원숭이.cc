#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int k, w, h;
int lst[200][200];
int v[31][200][200];
int hx[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int hy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
struct Pos {
	int x, y, t, s;
	bool operator<(const Pos& other) const {
		return t > other.t;
	}
};

int dijkstra() {
	priority_queue<Pos> pq;
	pq.push({ 0, 0, 0, 0 });
	v[0][0][0] = 1;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.x, cy = pos.y, ct = pos.t, cs = pos.s;
		if (cx == h - 1 && cy == w - 1) return ct;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < h && 0 <= ny && ny < w && !v[cs][nx][ny] && !lst[nx][ny]) {
				v[cs][nx][ny] = 1;
				pq.push({ nx, ny, ct + 1, cs });
			}
		}

		if (cs < k) {
			for (int i = 0; i < 8; ++i) {
				int nx = cx + hx[i], ny = cy + hy[i], ns = cs + 1;
				if (0 <= nx && nx < h && 0 <= ny && ny < w && !v[ns][nx][ny] && !lst[nx][ny]) {
					v[ns][nx][ny] = 1;
					pq.push({ nx, ny, ct + 1, ns });
				}
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> w >> h;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			cin >> lst[i][j];

	cout << dijkstra();
}