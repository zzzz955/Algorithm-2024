#include<iostream>
#include<cstring>
using namespace std;

int t, ans;
int lst[100][100];
int v[100][100][3];
int dy[] = {0, -1, 1 };

void input() {
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			cin >> lst[i][j];
		}
	}
}

bool chk(int sy, int dir) {
	int sx = 0;
	while (sx < 100) {
		if (dir) {
			int ny = sy + dy[dir];
			if (0 <= ny && ny < 100 && lst[sx][ny]) {
				if (v[sx][ny][dir]) break;
				v[sx][ny][dir] = 1;
				sy = ny;
				continue;
			}
			dir = 0;
			sx++;
			continue;
		}

		int l = sy + dy[1], r = sy + dy[2];
		if (0 <= l && lst[sx][l]) {
			dir = 1;
			if (v[sx][l][dir]) break;
			v[sx][l][dir] = 1;
			sy = l;
		}
		else if (r < 100 && lst[sx][r]) {
			dir = 2;
			if (v[sx][r][dir]) break;
			v[sx][r][dir] = 1;
			sy = r;
		}
		else sx++;
	}
	if (sx == 100 && lst[99][sy] == 2) return true;
	return false;
}

int solution() {
	for (int i = 0; i < 100; ++i) {
		if (lst[0][i] && chk(i, 0)) return i;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int c = 1; c <= 10; ++c) {
		cin >> t;
		memset(v, 0, sizeof(v));
		input();
		cout << "#" << t << " " << solution() << "\n";
	}
}