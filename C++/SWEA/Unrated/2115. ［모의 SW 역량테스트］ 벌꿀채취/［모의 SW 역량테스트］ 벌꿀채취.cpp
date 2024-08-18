#include<iostream>
#include<cstring>

using namespace std;

int tc, n, m, cc, max_val, max_temp;
int lst[11][11];
int temp[5];
int v[5];

void bt(int level, int val, int left) {
	if (level == m) {
		max_temp = max(max_temp, val);
		return;
	}

	for (int i = 0; i < m; i++) {
		if (!v[i] && left >= temp[i]) {
			v[i] = 1;
			bt(level + 1, val + (temp[i] * temp[i]), left - temp[i]);
			v[i] = 0;
		}
		else if (!v[i] && left < temp[i]) {
			v[i] = 1;
			bt(level + 1, val, left);
			v[i] = 0;
		}
	}
}

void dfs(int x, int y, int i1) {
	for (int i = x; i < n; i++) {
		for (int j = 0; j <= n - m; j++) {
			if (i == x && j < y + m) continue;
			for (int k = 0; k < m; k++) temp[k] = lst[i][j + k];
			memset(v, 0, sizeof(v));
			max_temp = 0;
			bt(0, 0, cc);
			max_val = max(max_val, max_temp + i1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	for (int c = 1; c <= tc; c++) {
		max_val = 0;
		cin >> n >> m >> cc;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> lst[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n - m; j++) {
				for (int k = 0; k < m; k++) temp[k] = lst[i][j + k];
				memset(v, 0, sizeof(v));
				max_temp = 0;
				bt(0, 0, cc);
				dfs(i, j, max_temp);
			}
		}
		cout << "#" << c << " " << max_val << "\n";
	}
}