#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int n, m, l, wall, blank, ans = 2e9;
int lst[50][50];
int v[50][50];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

struct Pos {
	int x, y;
};

vector<Pos> V;

int floodfill(vector<Pos>& cur) {
	queue<Pos> q;
	int remain = blank;
	for (const Pos& Pos : cur) {
		q.push({ Pos.x, Pos.y });
		v[Pos.x][Pos.y] = 1;
		remain--;
	}
	
	int result = 0;
	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y;
		if (v[cx][cy] > ans) return 2e9;
		if (v[cx][cy] > result) result = v[cx][cy];

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n && !lst[nx][ny] && !v[nx][ny]) {
				v[nx][ny] = v[cx][cy] + 1;
				q.push({ nx, ny });
				remain--;
			}
		}
	}
	return remain == 0 ? result - 1 : 2e9;
}

void bt(int level, int index, vector<Pos>& cur) {
	if (level == m) {
		memset(v, 0, sizeof(v));
		int result = floodfill(cur);
		ans = ans > result ? result : ans;
		return;
	}

	for (int i = index; i < l; ++i) {
		cur.push_back(V[i]);
		bt(level + 1, i + 1, cur);
		cur.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> lst[i][j];
			if (lst[i][j] == 2) {
				V.push_back({ i, j });
				lst[i][j] = 0;
			}
			if (lst[i][j] == 1) wall++;
		}
	}
	blank = n * n - wall;

	l = V.size();
	vector<Pos> cur;
	bt(0, 0, cur);

	if (ans == 2e9) cout << -1;
	else cout << ans;
}