#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int v[17];
int max_val, sdir;

struct Fish {
	int x, y, dir;
};

vector<Fish> fishes(18);
vector<vector<int>> lst(4, vector<int>(4));

void input() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b; cin >> a >> b;
			lst[i][j] = a;
			fishes[a] = { i, j, b - 1 };
		}
	}
}

void init() {
	max_val = lst[0][0];
	sdir = fishes[lst[0][0]].dir;
	v[lst[0][0]] = 1;
	lst[0][0] = 17;
}

void bt(int x, int y, int dir, int val, vector<vector<int>> map, vector<Fish> cur) {
	vector<Fish> temp = cur;
	for (int i = 1; i <= 16; i++) {
		if (v[i]) continue;
		Fish& fish = temp[i];
		int cx = fish.x, cy = fish.y, cd = fish.dir;
		for (int i = 0; i < 8; i++) {
			int nx = cx + dx[(cd + i) % 8], ny = cy + dy[(cd + i) % 8];
			if (0 <= nx && nx < 4 && 0 <= ny && ny < 4 && map[nx][ny] != 17) {
				if (map[nx][ny]) {
					Fish& target = temp[map[nx][ny]];
					target.x = cx;
					target.y = cy;
				}
				fish = { nx, ny, (cd + i) % 8 };
				swap(map[cx][cy], map[nx][ny]);
				break;
			}
		}
	}

	int idx = 0;
	while (++idx) {
		int nx = x + dx[dir] * idx, ny = y + dy[dir] * idx;
		if (0 <= nx && nx < 4 && 0 <= ny && ny < 4) {
			if (!map[nx][ny]) continue;
			vector<vector<int>> new_map = map;
			new_map[x][y] = 0;
			new_map[nx][ny] = 17;
			v[map[nx][ny]] = 1;
			bt(nx, ny, temp[map[nx][ny]].dir, val + map[nx][ny], new_map, temp);
			v[map[nx][ny]] = 0;
		}
		else break;
	}
	max_val = max(max_val, val);
	return;
}

int main() {
	input();
	init();
	bt(0, 0, sdir, max_val, lst, fishes);
	cout << max_val;
}