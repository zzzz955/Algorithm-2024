#include<iostream>
using namespace std;

int n, ans;
int s[8], w[8];

void bt(int level) {
	if (level == n) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) if (s[i] <= 0) cnt++;
		ans = max(ans, cnt);
		return;
	}
	if (s[level] <= 0) bt(level + 1);

	bool flag = 0;
	for (int i = 0; i < n; ++i) {
		if (i == level || s[i] <= 0 || s[level] <= 0) continue;
		flag = 1;

		s[level] -= w[i];
		s[i] -= w[level];
		bt(level + 1);
		s[level] += w[i];
		s[i] += w[level];
	}

	if (!flag) bt(level + 1);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> s[i] >> w[i];
	bt(0);
	cout << ans;
}