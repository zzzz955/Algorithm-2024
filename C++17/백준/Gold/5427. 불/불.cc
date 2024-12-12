#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int t, w, h;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
string lst[1000];
int v[1000][1000];
struct Pos {
	int x, y, t;
	char id;
	bool operator<(const Pos& other) const {
		if (t == other.t) {
			if (id == other.id) return false;
			return id == '@';
		}
		return t > other.t;
	}
};


int bfs(priority_queue<Pos>& pq) {
	while (!pq.empty()) {
		Pos pos = pq.top(); pq.pop();
		int cx = pos.x, cy = pos.y, ct = pos.t;
		char id = pos.id;
		if (id == '@') {
			if (cx == 0 || cx == h - 1 || cy == 0 || cy == w - 1) return ct;
		}

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i], nt = ct + 1;
			if (0 <= nx && nx < h && 0 <= ny && ny < w && !v[nx][ny] && lst[nx][ny] != '#') {
				if (id == '@' && lst[nx][ny] == '*') continue;
				v[nx][ny] = 1;
				lst[nx][ny] = id;
				pq.push({ nx, ny, nt, id });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> w >> h;

		priority_queue<Pos> pq;
		memset(v, 0, sizeof(v));
		for (int i = 0; i < h; ++i) {
			cin >> lst[i];
			for (int j = 0; j < w; ++j) {
				if (lst[i][j] == '@' || lst[i][j] == '*') {
					v[i][j] = 1;
					pq.push({ i, j, 1, lst[i][j] });
				}
			}
		}
		int result = bfs(pq);
		if (result == -1) cout << "IMPOSSIBLE\n";
		else cout << result << "\n";
	}

	
}