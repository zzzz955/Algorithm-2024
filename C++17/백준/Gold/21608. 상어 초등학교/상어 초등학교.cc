#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n;
int lst[21][21];
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
vector<int> friends[401];

struct Pos {
	int x, y, e;
};
Pos poses[401];

struct Prio {
	int x, y, e, c;
	bool operator<(const Prio& other) const {
		if (c < other.c) return true;
		if (c > other.c) return false;
		if (e < other.e) return true;
		if (e > other.e) return false;
		if (x > other.x) return true;
		if (x < other.x) return false;
		return y > other.y;
	}
};

void no_freinds(int now) {
	priority_queue<Prio> pq;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (!lst[i][j]) {
				int emp = 0;
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k], ny = j + dy[k];
					if (0 < nx && nx <= n && 0 < ny && ny <= n && !lst[nx][ny]) emp++;
				}
				pq.push({ i, j, emp });
			}
		}
	}
	Prio prio = pq.top();
	poses[now] = { prio.x, prio.y, 1 };
	lst[prio.x][prio.y] = now;
}

void solve(int now) {
	priority_queue<Prio> pq;
	for (int i = 0; i < 4; ++i) {
		int f; cin >> f;
		friends[now].push_back(f);
	}

	for (int i = 0; i < 4; ++i) {
		int f = friends[now][i];
		if (poses[f].e) {
			int cx = poses[f].x, cy = poses[f].y;
			for (int j = 0; j < 4; ++j) {
				int nx = cx + dx[j], ny = cy + dy[j];
				if (0 < nx && nx <= n && 0 < ny && ny <= n && !lst[nx][ny]) {
					int cnt = 0, emp = 0;
					for (int k = 0; k < 4; ++k) {
						int nnx = nx + dx[k], nny = ny + dy[k];
						if (0 < nnx && nnx <= n && 0 < nny && nny <= n) {
							if (!lst[nnx][nny]) {
								emp++;
								continue;
							}
							auto it = find(friends[now].begin(), friends[now].end(), lst[nnx][nny]);
							if (it != friends[now].end()) cnt++;
						}
					}
					pq.push({ nx, ny, emp, cnt });
				}
			}
		}
	}

	if (pq.empty()) no_freinds(now);
	else {
		Prio prio = pq.top();
		poses[now] = { prio.x, prio.y, 1 };
		lst[prio.x][prio.y] = now;
	}
}

void print() {
	cout << "\n";
	for (int i = 1; i <= n * n; ++i) {
		for (int j : friends[i]) cout << j << " ";
		cout << "\n";
	}

	cout << "\n";
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << lst[i][j] << " ";
		}
		cout << "\n";
	}
}

int calc() {
	int result = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int cnt = 0;
			int now = lst[i][j];
			for (int k = 0; k < 4; ++k) {
				int nx = i + dx[k], ny = j + dy[k];
				if (0 < nx && nx <= n && 0 < ny && ny <= n) {
					auto it = find(friends[now].begin(), friends[now].end(), lst[nx][ny]);
					if (it != friends[now].end()) cnt++;
				}
			}
			if (cnt == 4) result += 1000;
			else if (cnt == 3) result += 100;
			else if (cnt == 2) result += 10;
			else if (cnt == 1) result += 1;
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n * n; ++i) {
		int s; cin >> s;
		solve(s);
	}
	//print();
	cout << calc();
}