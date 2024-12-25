#include<iostream>
using namespace std;

int lst[9][9];
bool vc[9][10];
bool vr[9][10];
bool vs[9][10];
bool flag;

void bt(int x, int y) {
	if (flag) return;
	if (x == 9 && y == 0) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cout << lst[i][j] << " ";
			}
			cout << "\n";
		}
		flag = 1;
		return;
	}

	if (lst[x][y]) {
		if (y < 8) bt(x, y + 1);
		else bt(x + 1, 0);
	}
	else {
		for (int i = 1; i < 10; ++i) {
			int area = 3 * (x / 3) + (y / 3);
			if (vc[x][i] || vr[y][i] || vs[area][i]) continue;
			if (flag) break;
			vc[x][i] = 1;
			vr[y][i] = 1;
			vs[area][i] = 1;
			lst[x][y] = i;
			if (y < 8) bt(x, y + 1);
			else bt(x + 1, 0);
			vc[x][i] = 0;
			vr[y][i] = 0;
			vs[area][i] = 0;
			lst[x][y] = 0;
		}
	}
}

int main() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> lst[i][j];
			if (lst[i][j]) {
				int area = 3 * (i / 3) + (j / 3);
				vc[i][lst[i][j]] = 1;
				vr[j][lst[i][j]] = 1;
				vs[area][lst[i][j]] = 1;
			}
		}
	}
	bt(0, 0);
}