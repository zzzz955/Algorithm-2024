#include<iostream>
#include<vector>

using namespace std;
int n, t, flag, ans = 2e9;
int lst[21][21];
int v[20];

void bt(int level, vector<int>& start) {
	if (!ans) return;
	if (level == n / 2) {
		vector<int> link;
		int start_t = 0, link_t = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (i == j) continue;
				start_t += lst[start[i]][start[j]];
			}
		}
		for (int i = 1; i <= n; i++) if (!v[i]) link.push_back(i);
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (i == j) continue;
				link_t += lst[link[i]][link[j]];
			}
		}
		ans = min(ans, abs(start_t - link_t));
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (v[i]) continue;
		if (!start.empty() && start.back() > i) continue;
		v[i] = 1;
		start.push_back(i);
		bt(level + 1, start);
		start.pop_back();
		v[i] = 0;
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> lst[i][j];
		}
	}
	vector<int> start;
	bt(0, start);

	cout << ans;
}