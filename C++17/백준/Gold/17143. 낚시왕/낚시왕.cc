#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int r, c, m, ans;
int lst[101][101];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct Shark {
	int index, x, y, s, d, z;
	bool operator<(const Shark& other) const {
		return z < other.z;
	}
};
Shark sharks[10001];

void input() {
	cin >> r >> c >> m;
	for (int i = 1; i <= m; ++i) {
		int x, y, s, d, z; cin >> x >> y >> s >> d >> z;
		lst[x][y] = i;
		sharks[i] = { i, x, y, s, d - 1, z };
	}
}

Shark move(Shark& shark) {
	if (shark.d == 0 || shark.d == 1) {
		int remain = shark.s % ((r - 1) * 2);
		int cx = shark.x;
		while (remain--) {
			if (cx == 1) shark.d = 1;
			else if (cx == r) shark.d = 0;
			cx += dx[shark.d];
		}
		shark.x = cx;
		return shark;
	}
	if (shark.d == 2 || shark.d == 3) {
		int remain = shark.s % ((c - 1) * 2);
		int cy = shark.y;
		while (remain--) {
			if (cy == 1) shark.d = 2;
			else if (cy == c) shark.d = 3;
			cy += dy[shark.d];
		}
		shark.y = cy;
		return shark;
	}
}

void print(int fisher) {
	for (int i = 0; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			if (i == 0 && j == fisher) {
				cout << 'F' << " ";
				continue;
			}
			cout << lst[i][j] << " ";
		}
		cout << "\n";
	}
	cout << fisher << "\n";
}

void solution() {
	int col = 0;
	while (col++ < c) {
		//print(col);
		int row = 0;
		while (row++ < r) {
			if (lst[row][col]) {
				ans += sharks[lst[row][col]].z;
				lst[row][col] = 0;
				break;
			}
		}
		priority_queue<Shark> pq;
		for (int i = 1; i <= r; ++i) {
			for (int j = 1; j <= c; ++j) {
				if (lst[i][j]) {
					Shark& shark = sharks[lst[i][j]];
					lst[i][j] = 0;
					Shark moved_shark = move(shark);
					sharks[moved_shark.index] = moved_shark;
					pq.push(sharks[moved_shark.index]);
				}
			}
		}
		while (!pq.empty()) {
			Shark shark = pq.top(); pq.pop();
			if (lst[shark.x][shark.y]) continue;
			else lst[shark.x][shark.y] = shark.index;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution();
	cout << ans;
}