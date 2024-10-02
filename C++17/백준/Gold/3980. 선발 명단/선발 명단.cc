#include<iostream>

using namespace std;
int lst[11][11];
int v[11];
int tc, ans;

void bt(int level, int sum) {
	if (level == 11) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 11; i++) {
		if (v[i]) continue;
		if (!lst[level][i]) continue;
		v[i] = 1;
		bt(level + 1, sum + lst[level][i]);
		v[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		ans = 0;
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cin >> lst[i][j];
			}
		}
		bt(0, 0);
		cout << ans << "\n";
	}
}