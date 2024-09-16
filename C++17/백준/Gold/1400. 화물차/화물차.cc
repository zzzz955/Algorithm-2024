#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m, sx, sy, ex, ey;
int dx[] = { 1 ,-1 ,0 ,0 };
int dy[] = { 0, 0, 1, -1 };
string lst[20];

struct Pos {
	int x, y, d;
	bool operator<(const Pos& other) const {
		return d > other.d;
	}
};

struct Light {
	int dir, ew, sn, ct;
};

Light lights[60];

bool input() {
	cin >> n >> m;
	if (!n && !m) return false;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
		for (int j = 0; j < m; j++) {
			if (lst[i][j] == '.' || lst[i][j] == '#') continue;
			else if (lst[i][j] == 'A') sx = i, sy = j;
			else if (lst[i][j] == 'B') ex = i, ey = j;
			else cnt++;
		}
	}
	while (cnt--) {
		char idx, dir;
		int ew, sn;
		cin >> idx >> dir >> ew >> sn;
		lights[idx].dir = dir, lights[idx].ew = ew, lights[idx].sn = sn, lights[idx].ct = ew + sn;
	}
	return true;
}

void dijkstra() {
	priority_queue<Pos> pq;
	vector<vector<int>> dist(n, vector<int>(m, 1e9));
	pq.push({ sx, sy, 0 });
	dist[sx][sy] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.x, cy = pos.y, cd = pos.d;
		
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i], nd = cd + 1;
			if (0 <= nx && nx < n && 0 <= ny && ny < m && lst[nx][ny] != '.') {
				if (dist[nx][ny] <= nd) continue;
				if ('0' <= lst[nx][ny] && lst[nx][ny] <= '9') {
					Light light = lights[lst[nx][ny]];
					char dir = light.dir; int ew = light.ew, sn = light.sn, ct = light.ct;
					if (i > 1 && dir == '-' && cd % ct < ew);
					else if (i > 1 && dir == '|' && cd % ct >= sn);
					else if (i <= 1 && dir == '-' && cd % ct >= ew);
					else if (i <= 1 && dir == '|' && cd % ct < sn);
					else {
						pq.push({ cx, cy, nd });
						continue;
					}
				}
				dist[nx][ny] = nd;
				pq.push({ nx, ny, nd });
			}
		}
	}
	if (dist[ex][ey] == 1e9) cout << "impossible\n";
	else cout << dist[ex][ey] << "\n";
}

int main() {
	while (1) {
		if (!input()) break;
		dijkstra();
	}
}