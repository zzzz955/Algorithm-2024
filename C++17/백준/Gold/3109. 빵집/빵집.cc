#include<iostream>
using namespace std;

int r, c, ans;
string lst[10000];
bool v[10000][500];
int dx[] = { -1, 0, 1 };
int dy[] = { 1, 1, 1 };

bool dfs(int cx, int cy) {
	if (cy == c - 1) return true;
	for (int i = 0; i < 3; ++i) {
		int nx = cx + dx[i], ny = cy + dy[i];
		if (0 <= nx && nx < r && 0 <= ny && ny < c && !v[nx][ny] && lst[nx][ny] == '.') {
			v[nx][ny] = true;
			if (dfs(nx, ny)) return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; ++i) cin >> lst[i];

	for (int i = 0; i < r; ++i) {
		if (dfs(i, 0)) ans++;
	}
	cout << ans;
}