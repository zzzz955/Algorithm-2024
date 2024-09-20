#include<iostream>

using namespace std;

int lst[9][9], cnt = 0, flag = 0;
int cols[9][10] = { 0, };
int rows[9][10] = { 0, };
int groups[3][3][10] = { 0, };

void dfs(int col) {
	if (flag) return;
	if (!cnt) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << lst[i][j];
			}
			cout << "\n";
		}
		flag = 1;
		return;
	}
	for (int i = col; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (!lst[i][j]) {
				for (int k = 1; k <= 9; k++) {
					if (cols[i][k]) continue;
					if (rows[j][k]) continue;
					if (groups[i / 3][j / 3][k]) continue;
					cols[i][k] = 1;
					rows[j][k] = 1;
					groups[i / 3][j / 3][k] = 1;
					cnt--;
					lst[i][j] = k;
					dfs(i);
					lst[i][j] = 0;
					cnt++;
					cols[i][k] = 0;
					rows[j][k] = 0;
					groups[i / 3][j / 3][k] = 0;
				}
				return;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		string s; cin >> s;
		for (int j = 0; j < 9; j++) {
			lst[i][j] = s[j] - '0';
			if (lst[i][j]) {
				cols[i][lst[i][j]] = 1;
				rows[j][lst[i][j]] = 1;
				groups[i / 3][j / 3][lst[i][j]] = 1;
			}
			else cnt++;
		}
	}
	dfs(0);
}