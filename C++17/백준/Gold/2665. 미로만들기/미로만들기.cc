#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n;
string lst[51];
int v[51][51][101];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

struct Pos {
	int d, x, y;
};

struct compare {
	bool operator()(const Pos& left, const Pos& right) const {
		return left.d > right.d;
	}
};

int bfs() {
	priority_queue<Pos, vector<Pos>, compare> pq;
	pq.push({ 0, 0, 0 });
	v[0][0][0] = 1;

	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.x, cy = pos.y, cd = pos.d;
		if (cx == n - 1 && cy == n - 1) return cd;

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (lst[nx][ny] == '0' && !v[nx][ny][cd + 1]) {
					v[nx][ny][cd + 1] = 1;
					pq.push({ cd + 1, nx, ny });
				}
				if (lst[nx][ny] == '1' && !v[nx][ny][cd]) {
					v[nx][ny][cd] = 1;
					pq.push({ cd, nx, ny });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
	}
	cout << bfs();
}