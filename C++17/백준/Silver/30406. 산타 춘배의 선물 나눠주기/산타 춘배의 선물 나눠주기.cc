#include<iostream>
#include<vector>
using namespace std;

int n, ans;
int cnt[4];
int prio[4][4] = {
	{3, 2, 1, 0},
	{2, 3, 0, 1},
	{1, 0, 3, 2},
	{0, 1, 2, 3}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		cnt[a]++;
	}

	for (int j = 0; j < 4; ++j) {
		for (int i = 0; i < 4; ++i) {
			if (!cnt[i]) continue;
			int can = min(cnt[i], cnt[prio[i][j]]);
			ans += (i ^ prio[i][j]) * can;
			cnt[i] -= can;
			cnt[prio[i][j]] -= can;
		}
	}
	cout << ans;
}