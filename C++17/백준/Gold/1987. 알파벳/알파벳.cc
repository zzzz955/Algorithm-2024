#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ans = 0;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void dfs(vector<string>& lst, vector<int> v, int x, int y, int cnt) {
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[lst[nx][ny] - 65]) {
			v[lst[nx][ny] - 65] = 1;
			dfs(lst, v, nx, ny, cnt);
			v[lst[nx][ny] - 65] = 0;
		}
	}
	ans = max(ans, cnt);
}

int main() {
	cin >> n >> m;
	vector<string> lst(n);
	vector<int> v(26, 0);
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
	}
	v[lst[0][0] - 65] = 1;
	dfs(lst, v, 0, 0, 0);
	cout << ans;
}
