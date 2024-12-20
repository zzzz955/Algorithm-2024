#include<iostream>
#include<queue>
using namespace std;

int n, m, k;
struct Pos {
	int x, y, t, u;
	bool operator<(const Pos& other) const {
		return t > other.t;
	}
};
string lst[1000];
bool v[11][1000][1000];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int bfs() {
	priority_queue<Pos> pq;
	pq.push({ 0, 0, 1, 0 });
	v[0][0][0] = 1;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.x, cy = pos.y, ct = pos.t, cu = pos.u;
		if (cx == n - 1 && cy == m - 1) return ct;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (lst[nx][ny] == '0') {
					if (v[cu][nx][ny]) continue;
					v[cu][nx][ny] = 1;
					pq.push({ nx, ny, ct + 1, cu });
				}
				else {
					if (cu == k) continue;
					if (v[cu + 1][nx][ny]) continue;
					v[cu + 1][nx][ny] = 1;
					pq.push({ nx, ny, ct + 1, cu + 1 });
				}
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) cin >> lst[i];
	cout << bfs();
}