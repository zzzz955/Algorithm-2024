#include<iostream>
#include<queue>
using namespace std;

int n, m;
string lst[20];
bool v[20][20][20][20];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct Coin {
	int x1, y1, x2, y2, t;
};

int bfs(const Coin& s) {
	queue<Coin> q;
	q.push(s);
	v[s.x1][s.y1][s.x2][s.y2] = 1;

	while (!q.empty()) {
		Coin coin = q.front(); q.pop();
		int cx1 = coin.x1, cy1 = coin.y1, cx2 = coin.x2, cy2 = coin.y2, ct = coin.t;
		if (ct >= 10) continue;

		for (int i = 0; i < 4; ++i) {
			int nx1 = cx1 + dx[i], ny1 = cy1 + dy[i], nx2 = cx2 + dx[i], ny2 = cy2 + dy[i], nt = ct + 1;
			
			int flag1 = 0, flag2 = 0;
			if (0 > nx1 || nx1 >= n || 0 > ny1 || ny1 >= m) flag1 = 1;
			if (0 > nx2 || nx2 >= n || 0 > ny2 || ny2 >= m) flag2 = 1;
			if (flag1 ^ flag2) return nt;

			flag1 = 0, flag2 = 0;
			if (0 <= nx1 && nx1 < n && 0 <= ny1 && ny1 < m) {
				flag1 = 1;
				if (lst[nx1][ny1] == '#') nx1 = cx1, ny1 = cy1;
			}

			if (0 <= nx2 && nx2 < n && 0 <= ny2 && ny2 < m) {
				flag2 = 1;
				if (lst[nx2][ny2] == '#') nx2 = cx2, ny2 = cy2;
			}

			if (flag1 * flag2 == 0) continue;
			if (v[nx1][ny1][nx2][ny2]) continue;
			v[nx1][ny1][nx2][ny2] = 1;
			q.push({ nx1, ny1, nx2, ny2, nt });
		}
	}
	return -1;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> n >> m;
	Coin coin = { 0, 0, 0, 0, 0 };
	int index = 0;
	for (int i = 0; i < n; ++i) {
		cin >> lst[i];
		for (int j = 0; j < m; ++j) {
			if (lst[i][j] == 'o') {
				if (!index) {
					lst[i][j] = '.';
					coin.x1 = i;
					coin.y1 = j;
					index++;
				}
				else {
					lst[i][j] = '.';
					coin.x2 = i;
					coin.y2 = j;
				}
			}
		}
	}
	cout << bfs(coin);
}