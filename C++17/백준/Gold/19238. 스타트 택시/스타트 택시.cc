#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

int n, m, f, sx, sy;
int lst[21][21];
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
vector<vector<int>> dist[21][21];

struct Pos {
	int x, y, d, index;
	bool operator<(const Pos& other) const {
		if (d == other.d) {
			if (x == other.x) return y > other.y;
			return x > other.x;
		}
		return d > other.d;
	}
};

struct Pos2 {
	int x, y;
};

unordered_map<int, Pos2> start;
unordered_map<int, Pos2> dest;

void dijkstra(int x, int y, vector<vector<int>>& temp) {
	priority_queue<Pos> pq;
	pq.push({ x, y, 0 });
	temp[x][y] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.x, cy = pos.y, cd = pos.d;
		if (temp[cx][cy] < cd) continue;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i], nd = cd + 1;
			if (0 < nx && nx <= n && 0 < ny && ny <= n && !lst[nx][ny]) {
				if (temp[nx][ny] > nd) {
					temp[nx][ny] = nd;
					pq.push({ nx, ny, nd });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> f;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> lst[i][j];

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			vector<vector<int>> temp(n + 1, vector<int>(n + 1, 2e9));
			if (!lst[i][j]) dijkstra(i, j, temp);
			dist[i][j] = temp;
		}
	}

	cin >> sx >> sy;
	for (int i = 1; i <= m; ++i) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		start[i] = { x1, y1 };
		dest[i] = { x2, y2 };
	}

	while (!dest.empty()) {
		priority_queue<Pos> pq;
		for (auto i : start) {
			pq.push({ i.second.x, i.second.y, dist[sx][sy][i.second.x][i.second.y], i.first });
		}
		Pos pos = pq.top();
		f -= pos.d;
		if (f < 0) break;
		Pos2 pos2 = dest[pos.index];
		f -= dist[pos.x][pos.y][pos2.x][pos2.y];
		if (f < 0) break;
		f += dist[pos.x][pos.y][pos2.x][pos2.y] * 2;
		sx = pos2.x, sy = pos2.y;
		start.erase(pos.index);
		dest.erase(pos.index);
		pq.pop();
	}

	if (dest.empty()) cout << f;
	else cout << -1;
}