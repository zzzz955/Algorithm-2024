#include<iostream>
#include<cstring>

using namespace std;

int tc, mp;
int e[4];
int m[12];

void dfs(int level, int price) {
	if (level >= 12) {
		mp = min(mp, price);
		return;
	}
	if (mp <= price) return;
	for (int i = 0; i < 4; i++) {
		if (i == 0) dfs(level + 1, price + e[0] * m[level]);
		if (i == 1) dfs(level + 1, price + e[1]);
		if (i == 2) dfs(level + 3, price + e[2]);
		if (i == 3) dfs(level + 12, price + e[3]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	for (int c = 1; c <= tc; c++) {
		mp = 500000000;
		cin >> e[0] >> e[1] >> e[2] >> e[3];
		for (int i = 0; i < 12; i++) cin >> m[i];
		dfs(0, 0);
		cout << "#" << c << " " << mp << "\n";
	}
}