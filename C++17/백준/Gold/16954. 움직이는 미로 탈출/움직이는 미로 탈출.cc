#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<string> lst(8);

int ans;
int v[8][8][8];
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1, 0 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1, 0 };

struct Pos {
	int x, y;
};

void moving(vector<string>& map) {
	for (int i = 6; i >= 0; i--) swap(map[i], map[i + 1]);
	map[0] = "........";
}

void bt(int level, vector<string>& map, Pos pos) {
	if (ans) return;
	if (level == 8) {
		ans = 1;
		return;
	}
	vector<string> new_map = map;
	if (level) moving(new_map);
	int cx = pos.x, cy = pos.y;
	if (new_map[cx][cy] == '#') return;
	for (int i = 0; i < 9; i++) {
		int nx = cx + dx[i], ny = cy + dy[i];
		if (0 <= nx && nx < 8 && 0 <= ny && ny < 8 && !v[level][nx][ny] && new_map[nx][ny] != '#') {
			v[level][nx][ny] = 1;
			if (nx == 0 && ny == 7) ans = 1;
			bt(level + 1, new_map, { nx, ny });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 8; i++) cin >> lst[i];
	Pos pos = { 7, 0 };
	bt(0, lst, pos);
	cout << ans;
}