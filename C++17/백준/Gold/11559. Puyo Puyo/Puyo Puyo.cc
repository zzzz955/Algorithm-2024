#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

string lst[12];
int v[12][6];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int n = 12, m = 6, ans;

struct Pos {
	int x, y;
};

void getDown() {
	for (int j = 0; j < m; ++j) {
		vector<char> stack;
		for (int i = 0; i < n; ++i) {
			if (lst[i][j] != '.') {
				stack.push_back(lst[i][j]);
				lst[i][j] = '.';
			}
		}

		int index = n - 1;
		while (!stack.empty()) {
			lst[index--][j] = stack.back();
			stack.pop_back();
		}
	}
}

bool bfs(int sx, int sy, const char& ch) {
	queue<Pos> q;
	q.push({ sx, sy });
	v[sx][sy] = 1;
	queue<Pos> chain;
	chain.push({ sx, sy });

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny] && lst[nx][ny] == ch) {
				v[nx][ny] = 1;
				q.push({ nx, ny });
				chain.push({ nx, ny });
			}
		}
	}
	if (chain.size() >= 4) {
		while (!chain.empty()) {
			Pos pos = chain.front(); chain.pop();
			int cx = pos.x, cy = pos.y;
			lst[cx][cy] = '.';
		}
		return true;
	}
	return false;
}

bool solution() {
	bool flag = 0;
	memset(v, 0, sizeof(v));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (lst[i][j] == '.') continue;
			if (bfs(i, j, lst[i][j])) flag = 1;
		}
	}
	return flag;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < n; ++i) cin >> lst[i];
	while (solution()) {
		getDown();
		ans++;
	}
	cout << ans;
}