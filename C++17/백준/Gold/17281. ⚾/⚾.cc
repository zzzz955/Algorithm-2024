#include<iostream>
#include<vector>

using namespace std;
int n, ans = 0;
int inning[50][9];
int v[9] = { 0, };

int simul(vector<int>& turn) {
	int index = 0, point = 0;
	for (int i = 0; i < n; i++) {
		int base[4] = {0, 0, 0, 0};
		int out = 0;
		while (out < 3) {
			if (index >= 9) index = 0;
			if (inning[i][turn[index]] == 0) {
				out++;
				index++;
				continue;
			}
			int run = inning[i][turn[index]];
			if (run == 4) {
				point++;
				for (int i = 1; i < 4; i++) {
					if (base[i]) {
						base[i] = 0;
						point++;
					}
				}
			}
			else {
				for (int j = 3; j >= 0; j--) {
					if (!base[j]) continue;
					base[j] = 0;
					if (j + run >= 4) point++;
					else base[j + run] = 1;
				}
				base[run] = 1;
			}
			index++;
		}
	}
	return point;
}

void dfs(int level, vector<int>& turn) {
	if (level == 9) {
		ans = max(ans, simul(turn));
		return;
	}

	if (level == 3) {
		turn.push_back(0);
		dfs(level + 1, turn);
		turn.pop_back();
		return;
	}

	for (int i = 1; i < 9; i++) {
		if (v[i]) continue;
		v[i] = 1;
		turn.push_back(i);
		dfs(level + 1, turn);
		turn.pop_back();
		v[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) {
			int a; cin >> a;
			inning[i][j] = a;
		}
	}
	vector<int> temp;
	dfs(0, temp);
	cout << ans;
}