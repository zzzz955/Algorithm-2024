#include <iostream>
#include <vector>

using namespace std;

int n, cnt;
int vcol[15];
int vrd[30];
int vld[30];
int rd[15][15];
int ld[15][15];

void bt(int row) {
	if (row >= n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (vcol[i]) continue;
		if (vrd[rd[row][i]]) continue;
		if (vld[ld[row][i]]) continue;
		vcol[i] = 1;
		vrd[rd[row][i]] = 1;
		vld[ld[row][i]] = 1;
		bt(row + 1);
		vcol[i] = 0;
		vrd[rd[row][i]] = 0;
		vld[ld[row][i]] = 0;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			rd[i][j] = i - j + n;
			ld[i][j] = i + j;
		}
	}
	bt(0);
	cout << cnt;
}