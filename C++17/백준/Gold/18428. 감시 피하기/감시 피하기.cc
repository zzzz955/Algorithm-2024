#include<iostream>
#include<vector>

using namespace std;
int n, ans = false;
char lst[6][6];
int v[6][6];
int dx[] = { 0,  0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

struct Pos {
	int x, y;
};

vector<Pos> T;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> lst[i][j];
			if (lst[i][j] == 'T') T.push_back({ i, j });
		}
	}
}

void bfs() {
	for (Pos pos : T) {
		int cx = pos.x, cy = pos.y;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			while (0 <= nx && nx < n && 0 <= ny && ny < n && lst[nx][ny] != 'O') {
				if (lst[nx][ny] == 'S') return;
				nx += dx[i];
				ny += dy[i];
			}
		}
	}
	ans = true;
	return;
}

void dfs(int level, int row) {
	if (ans) return;
	if (level == 3) {
		bfs();
		return;
	}

	for (int i = row; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (lst[i][j] != 'X') continue;
			if (v[i][j]) continue;
			v[i][j] = 1;
			lst[i][j] = 'O';
			dfs(level + 1, i);
			lst[i][j] = 'X';
			v[i][j] = 0;
		}
	}
}

void solution() {
	dfs(0, 0);
}

int main() {
	input();
	solution();
	if (ans) cout << "YES";
	else cout << "NO";
}