#include<iostream>
#include<queue>
#include<unordered_set>

using namespace std;

vector<string> lst;
int group[1000000];
int groups[1000][1000] = { 0, };
int v[1000][1000] = { 0, };
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int n, m;

struct Pos {
	int x, y;
};

int chk(int sx, int sy) {
	int cnt = 0;
	unordered_set<int> keys;
	for (int i = 0; i < 4; i++) {
		int nx = sx + dx[i], ny = sy + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < m && lst[nx][ny] != '1' && groups[nx][ny]) keys.insert(groups[nx][ny]);
	}
	for (int key : keys) cnt += group[key];
	return cnt;
}

void floodfill(int sx, int sy, int key) {
	queue<Pos> q;
	q.push({ sx, sy });
	int cnt = 1;
	v[sx][sy] = 1;
	groups[sx][sy] = key;

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny] && lst[nx][ny] == '0') {
				v[nx][ny] = 1;
				groups[nx][ny] = key;
				cnt++;
				q.push({ nx , ny });
			}
		}
	}
	group[key] = cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	lst.resize(n);
	for (int i = 0; i < n; i++) cin >> lst[i];

	int index = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lst[i][j] == '0' && !v[i][j]) floodfill(i, j, index++);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lst[i][j] == '0') cout << 0;
			else cout << (chk(i, j) + 1) % 10;
		}
		cout << "\n";
	}
}