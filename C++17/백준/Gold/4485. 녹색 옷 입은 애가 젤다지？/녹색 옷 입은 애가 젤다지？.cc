#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, lst[125][125];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

struct Pos {
	int x, y, w;
	bool operator<(const Pos& other) const {
		return w > other.w;
	}
};

int dijkstra() {
	priority_queue<Pos> pq;
	pq.push({ 0, 0, lst[0][0] });
	vector<vector<int>> dist(n, vector<int>(n, 2e9));
	dist[0][0] = lst[0][0];

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.x, cy = pos.y, cw = pos.w;
		if (dist[cx][cy] != cw) continue;

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i], nw = cw;
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (dist[nx][ny] > cw + lst[nx][ny]) {
					dist[nx][ny] = cw + lst[nx][ny];
					pq.push({ nx, ny, dist[nx][ny] });
				}
			}
		}
	}
	return dist[n - 1][n - 1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc = 0;
	while (++tc) {
		cin >> n;
		if (!n) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> lst[i][j];
			}
		}
		cout << "Problem " << tc << ": " << dijkstra() << "\n";
	}
}