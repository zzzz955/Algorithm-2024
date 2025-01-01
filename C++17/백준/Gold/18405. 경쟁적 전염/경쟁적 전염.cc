#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n, k;
int lst[200][200];
bool v[200][200];
int dx[] = { 1, -1, 0 ,0 };
int dy[] = { 0, 0, 1, -1 };

struct Pos {
	int x, y, N;
	bool operator<(const Pos& other) const {
		return N > other.N;
	}
};
priority_queue<Pos> virus;

void floodfill() {
	priority_queue<Pos> next;
	while (!virus.empty()) {
		Pos pos = virus.top(); virus.pop();
		int cx = pos.x, cy = pos.y, cN = pos.N;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n && !v[nx][ny]) {
				v[nx][ny] = 1;
				lst[nx][ny] = cN;
				next.push({ nx, ny, cN });
			}
		}
	}
	swap(next, virus);
}

int solution() {
	int s, x, y; cin >> s >> x >> y;
	while (s--) floodfill();
	return lst[--x][--y];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> lst[i][j];
			if (lst[i][j]) {
				virus.push({ i, j, lst[i][j] });
				v[i][j] = 1;
			}
		}
	}
	cout << solution();
}