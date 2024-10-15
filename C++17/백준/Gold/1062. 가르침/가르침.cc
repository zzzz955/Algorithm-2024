#include<iostream>
#include<vector>

using namespace std;

int n, k, ans;
int v[125];
vector<int> path;
string lst[50];

void bt(int level) {
	if (level >= k - 5) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int flag = 1;
			int len = lst[i].size();
			for (int j = 4; j < len - 4; j++) {
				if (!v[lst[i][j]]) {
					flag = 0;
					break;
				}
			}
			if (flag) cnt++;
		}
		ans = max(ans, cnt);
		return;
	}

	for (int i = 'a'; i <= 'z'; i++) {
		if (v[i]) continue;
		if (!path.empty() && path.back() < i) continue;
		v[i] = 1;
		path.push_back(i);
		bt(level + 1);
		path.pop_back();
		v[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> lst[i];
	string s = "antic";
	for (int i = 0; i < 5; i++) v[s[i]] = 1;
	if (k >= 5) bt(0);
	cout << ans;
}