#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int w, h, idx;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string lst[100];
struct Pos {
	int x, y, v, dir;
	bool operator<(const Pos& other) const {
		return v > other.v;
	}
};
struct Path {
	int x, y, d;
};
Pos C[2];

void input() {
	cin >> w >> h;
	for (int i = 0; i < h; ++i) {
		cin >> lst[i];
		for (int j = 0; j < w; ++j) {
			if (lst[i][j] == 'C') C[idx++] = { i, j };
		}
	}
}

void print(vector<vector<int>> dist) {
	cout << "\n";
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (dist[i][j] != 1e9) cout << dist[i][j] << " ";
			else cout << '-' << " ";
		}
		cout << "\n";
	}
}

int dijkstra(int sd) {
	priority_queue<Pos> pq;
	pq.push({ C[0].x, C[0].y, 0, sd });
	vector<vector<int>> dist(h, vector<int>(w, 1e9));
	dist[C[0].x][C[0].y] = 0;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.x, cy = pos.y, cv = pos.v, cd = pos.dir;

		for (int i = cd; i < cd + 4; ++i) {
			int nx = cx + dx[i % 4], ny = cy + dy[i % 4], nv = cv, nd = i % 4;
			if (nd != cd) nv++;
			if (0 <= nx && nx < h && 0 <= ny && ny < w && lst[nx][ny] != '*') {
				if (dist[nx][ny] > nv) {
					dist[nx][ny] = nv;
					pq.push({ nx, ny, nv, nd });
				}
			}
		}
	}
	//print(dist);
	return dist[C[1].x][C[1].y];
}

int solution() {
	int ans = 1e9;
	for (int i = 0; i < 4; i++) {
		ans = min(ans, dijkstra(i));
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	cout << solution();
}