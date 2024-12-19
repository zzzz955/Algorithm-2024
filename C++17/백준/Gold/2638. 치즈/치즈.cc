#include<iostream>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;

int n, m;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int lst[100][100];
int v[100][100];
unordered_map<int, int> dic;
struct Pos {
	int x, y;
};
queue<Pos> q;
queue<Pos> air;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> lst[i][j];
			if (lst[i][j]) dic[i + j * 100] = 0;
		}
	}
}

bool spread() {
	vector<int> del;
	for (auto i : dic) {
		int cx = i.first % 100, cy = i.first / 100;
		if (i.second >= 2) {
			lst[cx][cy] = 0;
			v[cx][cy] = 1;
			air.push({ cx, cy });
			del.push_back(i.first);
		}
	}
	for (int i : del) dic.erase(i);
	if (dic.empty()) return true;
	return false;
}

void floodfill() {
	while (!air.empty()) {
		Pos pos = air.front(); air.pop();
		int cx = pos.x, cy = pos.y;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny]) {
				if (!lst[nx][ny]) {
					v[nx][ny] = 1;
					air.push({ nx, ny });
				}
				else dic[nx + ny * 100]++;
			}
		}
	}
}

int solution() {
	int ans = 0;
	air.push({ 0, 0 });
	v[0][0] = 1;
	while (++ans) {
		floodfill();
		if (spread()) break;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	cout << solution();
}